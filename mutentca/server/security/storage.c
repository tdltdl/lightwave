/*
 * Copyright © 2018 VMware, Inc.  All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the “License”); you may not
 * use this file except in compliance with the License.  You may obtain a copy
 * of the License at http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an “AS IS” BASIS, without
 * warranties or conditions of any kind, EITHER EXPRESS OR IMPLIED.  See the
 * License for the specific language governing permissions and limitations
 * under the License.
 */
#include "includes.h"

static
DWORD
_LwCASecurityDuplicateEncryptedData(
    PLWCA_BINARY_DATA pDataSrc,
    PLWCA_BINARY_DATA *ppDataDest
    );

/* interface between security and storage */
DWORD
LwCASecurityStoragePut(
    PVOID pUserData,
    PCSTR pcszKeyId,
    PLWCA_BINARY_DATA pEncryptedKey
    )
{
    DWORD dwError = 0;
    BOOLEAN bStorageLocked = FALSE;
    PLWCA_BINARY_DATA pCopiedEncryptedKey = NULL;

    if (IsNullOrEmptyString(pcszKeyId) || !pEncryptedKey)
    {
        dwError = LWCA_ERROR_INVALID_PARAMETER;
        BAIL_ON_LWCA_ERROR(dwError);
    }

    LWCA_LOCK_MUTEX(bStorageLocked, &gSecurityCtx.storageMutex);

    if (LwRtlHashMapFindKey(gSecurityCtx.pStorageMap, NULL, pcszKeyId) == 0)
    {
        dwError = LWCA_SECURITY_KEY_ALREADY_IN_CACHE;
        BAIL_ON_LWCA_ERROR(dwError);
    }

    dwError = _LwCASecurityDuplicateEncryptedData(
                  pEncryptedKey,
                  &pCopiedEncryptedKey);
    BAIL_ON_LWCA_ERROR(dwError);

    dwError = LwRtlHashMapInsert(
                  gSecurityCtx.pStorageMap,
                  (PVOID)pcszKeyId,
                  pCopiedEncryptedKey,
                  NULL);
    BAIL_ON_LWCA_ERROR(dwError);

    pCopiedEncryptedKey = NULL;

cleanup:
    LWCA_UNLOCK_MUTEX(bStorageLocked, &gSecurityCtx.storageMutex);
    return dwError;

error:
    LwCASecurityFreeBinaryData(pCopiedEncryptedKey);
    goto cleanup;
}

DWORD
LwCASecurityStorageGet(
    PVOID pUserData,
    PCSTR pcszCAId,
    PLWCA_BINARY_DATA *ppEncryptedData
    )
{
    /* TODO: get data from db */
    return 0;
}

DWORD
LwCASecurityRemoveEncryptedKeyFromCache(
    PCSTR pcszCAId
    )
{
    DWORD dwError = 0;

    if (IsNullOrEmptyString(pcszCAId))
    {
        dwError = LWCA_ERROR_INVALID_PARAMETER;
        BAIL_ON_LWCA_ERROR(dwError);
    }

    dwError = LwRtlHashMapRemove(
                  gSecurityCtx.pStorageMap,
                  (PVOID)pcszCAId,
                  NULL);
    if (dwError)
    {
        dwError = LWCA_SECURITY_KEY_NOT_IN_CACHE;
    }
    BAIL_ON_LWCA_ERROR(dwError);

error:
    return dwError;
}

DWORD
LwCASecurityGetEncryptedKey(
    PCSTR pcszCAId,
    PLWCA_KEY *ppEncryptedCAKey
    )
{
    DWORD dwError = 0;
    PLWCA_KEY pEncryptedCAKey = NULL;
    PLWCA_BINARY_DATA pEncryptedKey = NULL;
    BOOLEAN bStorageLocked = FALSE;

    if (IsNullOrEmptyString(pcszCAId) || !ppEncryptedCAKey)
    {
        dwError = LWCA_ERROR_INVALID_PARAMETER;
        BAIL_ON_LWCA_ERROR(dwError);
    }

    LWCA_LOCK_MUTEX(bStorageLocked, &gSecurityCtx.storageMutex);

    dwError = LwRtlHashMapFindKey(
            gSecurityCtx.pStorageMap,
            (PVOID *)&pEncryptedKey,
            pcszCAId);
    if (dwError)
    {
        dwError = LWCA_SECURITY_KEY_NOT_IN_CACHE;
        BAIL_ON_LWCA_ERROR(dwError);
    }

    /* convert to PLWCA_KEY */
    dwError = LwCACreateKey(
                  pEncryptedKey->pData,
                  pEncryptedKey->dwLength,
                  &pEncryptedCAKey);
    BAIL_ON_LWCA_ERROR(dwError);

    dwError = LwCASecurityRemoveEncryptedKeyFromCache(pcszCAId);
    BAIL_ON_LWCA_ERROR(dwError);

    *ppEncryptedCAKey = pEncryptedCAKey;

cleanup:
    LwCASecurityFreeBinaryData(pEncryptedKey);
    LWCA_LOCK_MUTEX(bStorageLocked, &gSecurityCtx.storageMutex);
    return dwError;

error:
    if (!IsNullOrEmptyString(pcszCAId))
    {
        LwCASecurityRemoveEncryptedKeyFromCache(pcszCAId);
    }
    LwCAFreeKey(pEncryptedCAKey);
    goto cleanup;
}

static
DWORD
_LwCASecurityDuplicateEncryptedData(
    PLWCA_BINARY_DATA pDataSrc,
    PLWCA_BINARY_DATA *ppDataDest
    )
{
    DWORD dwError = 0;
    PLWCA_BINARY_DATA pDataDest = NULL;

    dwError = VmAllocateMemory(sizeof(LWCA_BINARY_DATA), (PVOID *)&pDataDest);
    BAIL_ON_LWCA_ERROR(dwError);

    dwError = VmAllocateMemory(pDataSrc->dwLength, (PVOID *)&pDataDest->pData);
    BAIL_ON_LWCA_ERROR(dwError);

    memcpy(pDataDest->pData, pDataSrc->pData, pDataSrc->dwLength);

    pDataDest->dwLength = pDataSrc->dwLength;

    *ppDataDest = pDataDest;

cleanup:
    return dwError;

error:
    LwCASecurityFreeBinaryData(pDataDest);
    goto cleanup;
}