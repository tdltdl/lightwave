/*
 * Copyright © 2012-2016 VMware, Inc.  All Rights Reserved.
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



// config-posix.c

#ifndef _WIN32

DWORD
VmwPosixCfgReadStringValue(
    PCSTR               pszSubkey,
    PCSTR               pszName,
    PSTR*               ppszValue
    );

DWORD
VmwPosixCfgReadStringArrayValue(
    PCSTR               pszSubkey,
    PCSTR               pszName,
    PDWORD              pdwNumValues,
    PSTR                **pppszValues
    );

DWORD
VmwPosixCfgReadDWORDValue(
    PCSTR               pszSubkey,
    PCSTR               pszName,
    PDWORD              pdwValue
    );

DWORD
VmwPosixCfgSetDWORDValue(
    PCSTR           pszSubkey,
    PCSTR           pszName,
    DWORD           dwValue
    );

#endif

// config-win.c

#ifdef _WIN32

DWORD
VmwWinCfgOpenConnection(
    PVMW_CFG_CONNECTION* ppConnection
    );

DWORD
VmwWinCfgOpenRootKey(
    PVMW_CFG_CONNECTION pConnection,
    PCSTR               pszKeyName,
    DWORD               dwOptions,
    DWORD               dwAccess,
    PVMW_CFG_KEY*       ppKey
    );

DWORD
VmwWinCfgOpenKey(
    PVMW_CFG_CONNECTION pConnection,
    PVMW_CFG_KEY        pKey,
    PCSTR               pszSubKey,
    DWORD               dwOptions,
    DWORD               dwAccess,
    PVMW_CFG_KEY*       ppKey
    );

DWORD
VmwWinCfgReadStringValue(
    PVMW_CFG_KEY        pKey,
    PCSTR               pszSubkey,
    PCSTR               pszName,
    PSTR*               ppszValue
    );

DWORD
VmwWinCfgReadDWORDValue(
    PVMW_CFG_KEY        pKey,
    PCSTR               pszSubkey,
    PCSTR               pszName,
    PDWORD              pdwValue
    );

DWORD
VmwWinCfgSetValue(
    PVMW_CFG_KEY        pKey,
    PCSTR               pszValue,
    DWORD               dwType,
    PBYTE               pValue,
    DWORD               dwSize
    );

VOID
VmwWinCfgCloseKey(
    PVMW_CFG_KEY pKey
    );

VOID
VmwWinCfgCloseConnection(
    PVMW_CFG_CONNECTION pConnection
    );

#endif
