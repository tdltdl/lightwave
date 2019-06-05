/*
 * Copyright © 2012-2015 VMware, Inc.  All Rights Reserved.
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



/*
 * Module Name: VDIR
 *
 * Filename: vmdirerrorcode.h
 *
 * Abstract:
 *
 * Common error code map
 *
 */

#ifndef VMDIRERRORS_H_
#define VMDIRERRORS_H_

#define VMDIR_ERROR_BASE            9000

#define VMDIR_SYSTEM_ERROR_BASE           0
#define VMDIR_GENERIC_ERROR_BASE          100
#define VMDIR_CUSTOMIZED_LDAP_ERROR_BASE  300
#define VMDIR_QUEUE_ERROR_BASE            450
#define VMDIR_SCHEMA_ERROR_BASE           600
#define VMDIR_BACKEND_ERROR_BASE          700
#define VMDIR_REST_ERROR_BASE             900 /* Using the same REST error base as in lwraft */

#define VMDIR_SUCCESS   0

#define VMDIR_RANGE(n,x,y)                  (((x) <= (n)) && ((n) <= (y)))

// VmDir error space 9000~9999
#define IS_VMDIR_ERROR_SPACE(n) \
    VMDIR_RANGE((n), (VMDIR_ERROR_BASE), (VMDIR_ERROR_BASE + 999)) || n == VMDIR_SUCCESS

// WARNING: definitions MUST stay in sync with error-message table in client defines.h

// system level error 9000~9099
#define VMDIR_ERROR_OPERATION_NOT_PERMITTED           (VMDIR_ERROR_BASE + VMDIR_SYSTEM_ERROR_BASE + 1 )      // 9001
#define VMDIR_ERROR_NO_SUCH_FILE_OR_DIRECTORY         (VMDIR_ERROR_BASE + VMDIR_SYSTEM_ERROR_BASE + 2 )      // 9002
#define VMDIR_ERROR_IO                                (VMDIR_ERROR_BASE + VMDIR_SYSTEM_ERROR_BASE + 3 )      // 9003
#define VMDIR_ERROR_NO_MEMORY                         (VMDIR_ERROR_BASE + VMDIR_SYSTEM_ERROR_BASE + 4 )      // 9004
#define VMDIR_ERROR_INVALID_PARAMETER                 (VMDIR_ERROR_BASE + VMDIR_SYSTEM_ERROR_BASE + 5 )      // 9005
#define VMDIR_ERROR_NOT_FOUND                         (VMDIR_ERROR_BASE + VMDIR_SYSTEM_ERROR_BASE + 6 )      // 9006
#define VMDIR_ERROR_CANNOT_LOAD_LIBRARY               (VMDIR_ERROR_BASE + VMDIR_SYSTEM_ERROR_BASE + 7 )      // 9007
#define VMDIR_ERROR_INVALID_STATE                     (VMDIR_ERROR_BASE + VMDIR_SYSTEM_ERROR_BASE + 8 )      // 9008
#define VMDIR_ERROR_DEPRECATED_FUNCTION               (VMDIR_ERROR_BASE + VMDIR_SYSTEM_ERROR_BASE + 9 )      // 9009
#define VMDIR_ERROR_FILE_OPEN                         (VMDIR_ERROR_BASE + VMDIR_SYSTEM_ERROR_BASE + 10 )     // 9010
#define VMDIR_ERROR_FILE_READ                         (VMDIR_ERROR_BASE + VMDIR_SYSTEM_ERROR_BASE + 11 )     // 9011
#define VMDIR_ERROR_PATH_EXISTS                       (VMDIR_ERROR_BASE + VMDIR_SYSTEM_ERROR_BASE + 12 )     // 9012
#define VMDIR_ERROR_INVALID_PATH                      (VMDIR_ERROR_BASE + VMDIR_SYSTEM_ERROR_BASE + 13 )     // 9013
#define VMDIR_ERROR_INVALID_MEMORY                    (VMDIR_ERROR_BASE + VMDIR_SYSTEM_ERROR_BASE + 14 )     // 9014

// generic error 9100~9599
#define IS_VMDIR_GENERIC_ERROR_SPACE(n) \
    VMDIR_RANGE((n),(VMDIR_ERROR_BASE + VMDIR_GENERIC_ERROR_BASE) , (VMDIR_ERROR_BASE + VMDIR_GENERIC_ERROR_BASE + 499) )

#define VMDIR_ERROR_GENERIC                           (VMDIR_ERROR_BASE + VMDIR_GENERIC_ERROR_BASE + 0 )      // 9100
#define VMDIR_ERROR_INVALID_CONFIGURATION             (VMDIR_ERROR_BASE + VMDIR_GENERIC_ERROR_BASE + 1 )      // 9101
#define VMDIR_ERROR_DATA_CONSTRAINT_VIOLATION         (VMDIR_ERROR_BASE + VMDIR_GENERIC_ERROR_BASE + 2 )      // 9102
#define VMDIR_ERROR_BAD_ATTRIBUTE_DATA                (VMDIR_ERROR_BASE + VMDIR_GENERIC_ERROR_BASE + 3 )      // 9103
#define VMDIR_ERROR_INVALID_REALM                     (VMDIR_ERROR_BASE + VMDIR_GENERIC_ERROR_BASE + 4 )      // 9104
#define VMDIR_ERROR_PARENT_NOT_FOUND                  (VMDIR_ERROR_BASE + VMDIR_GENERIC_ERROR_BASE + 5 )      // 9105
#define VMDIR_ERROR_ENTRY_NOT_FOUND                   (VMDIR_ERROR_BASE + VMDIR_GENERIC_ERROR_BASE + 6 )      // 9106
#define VMDIR_ERROR_ENTRY_ALREADY_EXIST               (VMDIR_ERROR_BASE + VMDIR_GENERIC_ERROR_BASE + 7 )      // 9107
#define VMDIR_ERROR_AUTH_METHOD_NOT_SUPPORTED         (VMDIR_ERROR_BASE + VMDIR_GENERIC_ERROR_BASE + 8 )      // 9108
#define VMDIR_ERROR_TIMELIMIT_EXCEEDED                (VMDIR_ERROR_BASE + VMDIR_GENERIC_ERROR_BASE + 9 )      // 9109
#define VMDIR_ERROR_SIZELIMIT_EXCEEDED                (VMDIR_ERROR_BASE + VMDIR_GENERIC_ERROR_BASE + 10)      // 9110
#define VMDIR_ERROR_SASL_BIND_IN_PROGRESS             (VMDIR_ERROR_BASE + VMDIR_GENERIC_ERROR_BASE + 11)      // 9111
#define VMDIR_ERROR_BUSY                              (VMDIR_ERROR_BASE + VMDIR_GENERIC_ERROR_BASE + 12)      // 9112
#define VMDIR_ERROR_UNAVAILABLE                       (VMDIR_ERROR_BASE + VMDIR_GENERIC_ERROR_BASE + 13)      // 9113
#define VMDIR_ERROR_UNWILLING_TO_PERFORM              (VMDIR_ERROR_BASE + VMDIR_GENERIC_ERROR_BASE + 14)      // 9114
#define VMDIR_ERROR_LOCK_DEADLOCK                     (VMDIR_ERROR_BASE + VMDIR_GENERIC_ERROR_BASE + 15)      // 9115
#define VMDIR_ERROR_NO_USN                            (VMDIR_ERROR_BASE + VMDIR_GENERIC_ERROR_BASE + 16)      // 9116
#define VMDIR_ERROR_NOT_ALLOWED_ON_NONLEAF            (VMDIR_ERROR_BASE + VMDIR_GENERIC_ERROR_BASE + 17)      // 9117
#define VMDIR_ERROR_DOMAIN_NOT_FOUND                  (VMDIR_ERROR_BASE + VMDIR_GENERIC_ERROR_BASE + 18)      // 9118
#define VMDIR_ERROR_NO_SSL_CTX                        (VMDIR_ERROR_BASE + VMDIR_GENERIC_ERROR_BASE + 19)      // 9119
#define VMDIR_ERROR_SSL_CERT_FILE_NOT_FOUND           (VMDIR_ERROR_BASE + VMDIR_GENERIC_ERROR_BASE + 20)      // 9120
#define VMDIR_ERROR_SSL                               (VMDIR_ERROR_BASE + VMDIR_GENERIC_ERROR_BASE + 21)      // 9121
#define VMDIR_ERROR_SRP                               (VMDIR_ERROR_BASE + VMDIR_GENERIC_ERROR_BASE + 22)      // 9122
#define VMDIR_ERROR_INVALID_REQUEST                   (VMDIR_ERROR_BASE + VMDIR_GENERIC_ERROR_BASE + 23)      // 9123
#define VMDIR_ERROR_INVALID_RESULT                    (VMDIR_ERROR_BASE + VMDIR_GENERIC_ERROR_BASE + 24)      // 9124
#define VMDIR_ERROR_ACCESS_DENIED                     (VMDIR_ERROR_BASE + VMDIR_GENERIC_ERROR_BASE + 25)      // 9125
#define VMDIR_ERROR_CANNOT_CONNECT_VMDIR              (VMDIR_ERROR_BASE + VMDIR_GENERIC_ERROR_BASE + 26)      // 9126
#define VMDIR_ERROR_SERVER_DOWN                       (VMDIR_ERROR_BASE + VMDIR_GENERIC_ERROR_BASE + 27)      // 9127
#define VMDIR_ERROR_NO_FUNC_LVL                       (VMDIR_ERROR_BASE + VMDIR_GENERIC_ERROR_BASE + 28)      // 9128
#define VMDIR_ERROR_INVALID_FUNC_LVL                  (VMDIR_ERROR_BASE + VMDIR_GENERIC_ERROR_BASE + 29)      // 9129
#define VMDIR_ERROR_INCOMPLETE_MAX_DFL                (VMDIR_ERROR_BASE + VMDIR_GENERIC_ERROR_BASE + 30)      // 9130
#define VMDIR_ERROR_RESTORE_ERROR                     (VMDIR_ERROR_BASE + VMDIR_GENERIC_ERROR_BASE + 31)      // 9131
#define VMDIR_ERROR_AUTH_BAD_DATA                     (VMDIR_ERROR_BASE + VMDIR_GENERIC_ERROR_BASE + 32)      // 9132
#define VMDIR_ERROR_AFD_UNAVAILABLE                   (VMDIR_ERROR_BASE + VMDIR_GENERIC_ERROR_BASE + 33)      // 9133
#define VMDIR_ERROR_OIDC_UNAVAILABLE                  (VMDIR_ERROR_BASE + VMDIR_GENERIC_ERROR_BASE + 34)      // 9134
#define VMDIR_ERROR_ALREADY_PROMOTED                  (VMDIR_ERROR_BASE + VMDIR_GENERIC_ERROR_BASE + 35)      // 9135
#define VMDIR_ERROR_NETWORK_TIMEOUT                   (VMDIR_ERROR_BASE + VMDIR_GENERIC_ERROR_BASE + 36)      // 9136
#define VMDIR_ERROR_TOO_MANY_ENTRY                    (VMDIR_ERROR_BASE + VMDIR_GENERIC_ERROR_BASE + 37)      // 9137
#define VMDIR_ERROR_INTERNAL_SEARCH_LIMIT             (VMDIR_ERROR_BASE + VMDIR_GENERIC_ERROR_BASE + 38)      // 9138
#define VMDIR_ERROR_INTERNAL_SIZE_LIMIT               (VMDIR_ERROR_BASE + VMDIR_GENERIC_ERROR_BASE + 39)      // 9139
#define VMDIR_ERROR_NO_ATTRIBUTE_METADATA             (VMDIR_ERROR_BASE + VMDIR_GENERIC_ERROR_BASE + 40)      // 9140

// SID/ACL 9200 ~9229
#define VMDIR_ERROR_RID_LIMIT_EXCEEDED                (VMDIR_ERROR_BASE + VMDIR_GENERIC_ERROR_BASE + 100 )    // 9200
#define VMDIR_ERROR_ORG_ID_GEN_FAILED                 (VMDIR_ERROR_BASE + VMDIR_GENERIC_ERROR_BASE + 101 )    // 9201
#define VMDIR_ERROR_NO_OBJECT_SID_GEN                 (VMDIR_ERROR_BASE + VMDIR_GENERIC_ERROR_BASE + 102 )    // 9202
#define VMDIR_ERROR_NO_SECURITY_DESCRIPTOR            (VMDIR_ERROR_BASE + VMDIR_GENERIC_ERROR_BASE + 103 )    // 9203
#define VMDIR_ERROR_NO_OBJECTSID_ATTR                 (VMDIR_ERROR_BASE + VMDIR_GENERIC_ERROR_BASE + 104 )    // 9204
#define VMDIR_ERROR_TOKEN_IN_USE                      (VMDIR_ERROR_BASE + VMDIR_GENERIC_ERROR_BASE + 105 )    // 9205
#define VMDIR_ERROR_NO_MYSELF                         (VMDIR_ERROR_BASE + VMDIR_GENERIC_ERROR_BASE + 106 )    // 9206
#define VMDIR_ERROR_INSUFFICIENT_ACCESS               (VMDIR_ERROR_BASE + VMDIR_GENERIC_ERROR_BASE + 107)     // 9207
#define VMDIR_ERROR_ACL_VIOLATION                     (VMDIR_ERROR_BASE + VMDIR_GENERIC_ERROR_BASE + 108)     // 9208
#define VMDIR_ERROR_INVALID_ACE                       (VMDIR_ERROR_BASE + VMDIR_GENERIC_ERROR_BASE + 109)     // 9209
#define VMDIR_ERROR_ACE_NOT_FOUND                     (VMDIR_ERROR_BASE + VMDIR_GENERIC_ERROR_BASE + 110)     // 9210

// user account management 9230 ~ 9269
#define VMDIR_ERROR_PASSWORD_TOO_LONG                 (VMDIR_ERROR_BASE + VMDIR_GENERIC_ERROR_BASE + 130 )    // 9230
#define VMDIR_ERROR_PASSWORD_HASH                     (VMDIR_ERROR_BASE + VMDIR_GENERIC_ERROR_BASE + 131 )    // 9231
#define VMDIR_ERROR_PASSWORD_POLICY_VIOLATION         (VMDIR_ERROR_BASE + VMDIR_GENERIC_ERROR_BASE + 132 )    // 9232
#define VMDIR_ERROR_USER_LOCKOUT                      (VMDIR_ERROR_BASE + VMDIR_GENERIC_ERROR_BASE + 133 )    // 9233
#define VMDIR_ERROR_USER_INVALID_CREDENTIAL           (VMDIR_ERROR_BASE + VMDIR_GENERIC_ERROR_BASE + 134 )    // 9234
#define VMDIR_ERROR_KERBEROS_ERROR                    (VMDIR_ERROR_BASE + VMDIR_GENERIC_ERROR_BASE + 135 )    // 9235
#define VMDIR_ERROR_KERBEROS_REALM_OFFLINE            (VMDIR_ERROR_BASE + VMDIR_GENERIC_ERROR_BASE + 136 )    // 9236
#define VMDIR_ERROR_NO_CRED_CACHE_NAME                (VMDIR_ERROR_BASE + VMDIR_GENERIC_ERROR_BASE + 137 )    // 9237
#define VMDIR_ERROR_NO_CRED_CACHE_FOUND               (VMDIR_ERROR_BASE + VMDIR_GENERIC_ERROR_BASE + 138 )    // 9238
#define VMDIR_ERROR_PASSWORD_EXPIRED                  (VMDIR_ERROR_BASE + VMDIR_GENERIC_ERROR_BASE + 139 )    // 9239
#define VMDIR_ERROR_ACCOUNT_DISABLED                  (VMDIR_ERROR_BASE + VMDIR_GENERIC_ERROR_BASE + 140 )    // 9240
#define VMDIR_ERROR_ACCOUNT_LOCKED                    (VMDIR_ERROR_BASE + VMDIR_GENERIC_ERROR_BASE + 141 )    // 9241
#define VMDIR_ERROR_INVALID_POLICY_DEFINITION         (VMDIR_ERROR_BASE + VMDIR_GENERIC_ERROR_BASE + 142 )    // 9242
#define VMDIR_ERROR_USER_NO_CREDENTIAL                (VMDIR_ERROR_BASE + VMDIR_GENERIC_ERROR_BASE + 143 )    // 9243
#define VMDIR_ERROR_PASSWORD_INSUFFICIENT_QUALITY     (VMDIR_ERROR_BASE + VMDIR_GENERIC_ERROR_BASE + 144 )    // 9244
#define VMDIR_ERROR_PASSWORD_TOO_SHORT                (VMDIR_ERROR_BASE + VMDIR_GENERIC_ERROR_BASE + 145 )    // 9245
#define VMDIR_ERROR_PASSWORD_IN_HISTORY               (VMDIR_ERROR_BASE + VMDIR_GENERIC_ERROR_BASE + 146 )    // 9246

// Tools 9270 ~ 9289
#define VMDIR_ERROR_VDCPROMO                          (VMDIR_ERROR_BASE + VMDIR_GENERIC_ERROR_BASE + 170 )    // 9270
#define VMDIR_ERROR_VDCMERGE                          (VMDIR_ERROR_BASE + VMDIR_GENERIC_ERROR_BASE + 171 )    // 9271
#define VMDIR_ERROR_VDCSPLIT                          (VMDIR_ERROR_BASE + VMDIR_GENERIC_ERROR_BASE + 172 )    // 9272
#define VMDIR_ERROR_VDCREPADMIN_GENERAL               (VMDIR_ERROR_BASE + VMDIR_GENERIC_ERROR_BASE + 173 )    // 9273
#define VMDIR_ERROR_VDCREPADMIN_TOO_FEW_REPLICATION_PARTNERS  (VMDIR_ERROR_BASE + VMDIR_GENERIC_ERROR_BASE + 174 )    // 9274
#define VMDIR_ERROR_RESTORE_PARTNERS_UNAVAILABLE      (VMDIR_ERROR_BASE + VMDIR_GENERIC_ERROR_BASE + 175 )    // 9275
#define VMDIR_ERROR_OPTION_UNKNOWN                    (VMDIR_ERROR_BASE + VMDIR_GENERIC_ERROR_BASE + 176 )    // 9276
#define VMDIR_ERROR_OPTION_INVALID                    (VMDIR_ERROR_BASE + VMDIR_GENERIC_ERROR_BASE + 177 )    // 9277

// pagedsearch 9290 ~ 9299
#define VMDIR_ERROR_NO_PAGED_SEARCH_CONTEXT            (VMDIR_ERROR_BASE + VMDIR_GENERIC_ERROR_BASE + 190 )    // 9290
#define VMDIR_ERROR_INVALID_PAGED_SEARCH_REQUEST       (VMDIR_ERROR_BASE + VMDIR_GENERIC_ERROR_BASE + 191 )    // 9291

// vector processing 9300 ~ 9310
#define VMDIR_ERROR_INVALID_VECTOR_STR                 (VMDIR_ERROR_BASE + VMDIR_GENERIC_ERROR_BASE + 200 )    // 9300

// write operations error 9311 ~ 9320
#define VMDIR_ERROR_ML_WRITE_TIMEOUT                   (VMDIR_ERROR_BASE + VMDIR_GENERIC_ERROR_BASE + 211 )    //9311

//////////////////////////////////////////////////////////////////////////////////////////////////
// customized LDAP return code (range 9300 - 9399)
//////////////////////////////////////////////////////////////////////////////////////////////////
#define IS_CUSTOMIZED_VMDIR_LDAP_ERROR_SPACE(n) \
    VMDIR_RANGE((n),(VMDIR_ERROR_BASE + VMDIR_CUSTOMIZED_LDAP_ERROR_BASE) , (VMDIR_ERROR_BASE + VMDIR_CUSTOMIZED_LDAP_ERROR_BASE + 99) )

#define VMDIR_LDAP_ERROR_PRE_CONDITION                (VMDIR_ERROR_BASE + VMDIR_CUSTOMIZED_LDAP_ERROR_BASE + 0) // 9300

//////////////////////////////////////////////////////////////////////////////////////////////////
// vmdir queue error (range 9450 - 9499)
//////////////////////////////////////////////////////////////////////////////////////////////////
#define IS_VMDIR_QUEUE_ERROR_SPACE(n) \
    VMDIR_RANGE((n),(VMDIR_ERROR_BASE + VMDIR_QUEUE_ERROR_BASE) , (VMDIR_ERROR_BASE + VMDIR_QUEUE_ERROR_BASE + 49))

#define VMDIR_ERROR_QUEUE_EMPTY                       (VMDIR_ERROR_BASE + VMDIR_QUEUE_ERROR_BASE + 0 )   // 9450

//////////////////////////////////////////////////////////////////////////////////////////////////
// schema error (range 9600 - 9699)
//////////////////////////////////////////////////////////////////////////////////////////////////
#define IS_VMDIR_SCHEMA_ERROR_SPACE(n) \
    VMDIR_RANGE((n),(VMDIR_ERROR_BASE + VMDIR_SCHEMA_ERROR_BASE) , (VMDIR_ERROR_BASE + VMDIR_SCHEMA_ERROR_BASE + 99) )

#define VMDIR_ERROR_NO_SCHEMA                         (VMDIR_ERROR_BASE + VMDIR_SCHEMA_ERROR_BASE + 0 )   // 9600
#define VMDIR_ERROR_INVALID_SCHEMA                    (VMDIR_ERROR_BASE + VMDIR_SCHEMA_ERROR_BASE + 1 )   // 9601
#define VMDIR_ERROR_INVALID_DN                        (VMDIR_ERROR_BASE + VMDIR_SCHEMA_ERROR_BASE + 2 )   // 9602
#define VMDIR_ERROR_INVALID_SYNTAX                    (VMDIR_ERROR_BASE + VMDIR_SCHEMA_ERROR_BASE + 3 )   // 9603
#define VMDIR_ERROR_INVALID_ENTRY                     (VMDIR_ERROR_BASE + VMDIR_SCHEMA_ERROR_BASE + 4 )   // 9604
#define VMDIR_ERROR_INVALID_ATTRIBUTETYPES            (VMDIR_ERROR_BASE + VMDIR_SCHEMA_ERROR_BASE + 5 )   // 9605
#define VMDIR_ERROR_INVALID_OBJECTCLASSES             (VMDIR_ERROR_BASE + VMDIR_SCHEMA_ERROR_BASE + 6 )   // 9606
#define VMDIR_ERROR_INVALID_DITCONTENTRULES           (VMDIR_ERROR_BASE + VMDIR_SCHEMA_ERROR_BASE + 7 )   // 9607
#define VMDIR_ERROR_INVALID_NAMEFORMS                 (VMDIR_ERROR_BASE + VMDIR_SCHEMA_ERROR_BASE + 8 )   // 9608
#define VMDIR_ERROR_INVALID_DITSTRUCTURERULES         (VMDIR_ERROR_BASE + VMDIR_SCHEMA_ERROR_BASE + 9 )   // 9609
#define VMDIR_ERROR_NO_SUCH_SYNTAX                    (VMDIR_ERROR_BASE + VMDIR_SCHEMA_ERROR_BASE + 10 )  // 9610
#define VMDIR_ERROR_NO_SUCH_ATTRIBUTE                 (VMDIR_ERROR_BASE + VMDIR_SCHEMA_ERROR_BASE + 11 )  // 9611
#define VMDIR_ERROR_NO_SUCH_OBJECTCLASS               (VMDIR_ERROR_BASE + VMDIR_SCHEMA_ERROR_BASE + 12 )  // 9612
#define VMDIR_ERROR_NO_SUCH_DITCONTENTRULES           (VMDIR_ERROR_BASE + VMDIR_SCHEMA_ERROR_BASE + 13 )  // 9613
#define VMDIR_ERROR_NO_SUCH_NAMEFORMS                 (VMDIR_ERROR_BASE + VMDIR_SCHEMA_ERROR_BASE + 14 )  // 9614
#define VMDIR_ERROR_NO_SUCH_DITSTRUCTURERULES         (VMDIR_ERROR_BASE + VMDIR_SCHEMA_ERROR_BASE + 15 )  // 9615
#define VMDIR_ERROR_OBJECTCLASS_VIOLATION             (VMDIR_ERROR_BASE + VMDIR_SCHEMA_ERROR_BASE + 16 )  // 9616
#define VMDIR_ERROR_STRUCTURE_VIOLATION               (VMDIR_ERROR_BASE + VMDIR_SCHEMA_ERROR_BASE + 17 )  // 9617
#define VMDIR_ERROR_NAMING_VIOLATION                  (VMDIR_ERROR_BASE + VMDIR_SCHEMA_ERROR_BASE + 18 )  // 9618
#define VMDIR_ERROR_TYPE_OR_VALUE_EXISTS              (VMDIR_ERROR_BASE + VMDIR_SCHEMA_ERROR_BASE + 19 )  // 9619
#define VMDIR_ERROR_UNDEFINED_TYPE                    (VMDIR_ERROR_BASE + VMDIR_SCHEMA_ERROR_BASE + 20 )  // 9620
#define VMDIR_ERROR_SCHEMA_MISMATCH                   (VMDIR_ERROR_BASE + VMDIR_SCHEMA_ERROR_BASE + 21 )  // 9621
#define VMDIR_ERROR_SCHEMA_BAD_METADATA               (VMDIR_ERROR_BASE + VMDIR_SCHEMA_ERROR_BASE + 22 )  // 9622
#define VMDIR_ERROR_SCHEMA_NOT_COMPATIBLE             (VMDIR_ERROR_BASE + VMDIR_SCHEMA_ERROR_BASE + 23 )  // 9623
#define VMDIR_ERROR_SCHEMA_UPDATE_PASSTHROUGH         (VMDIR_ERROR_BASE + VMDIR_SCHEMA_ERROR_BASE + 24 )  // 9624
#define VMDIR_ERROR_INVALID_NORMALIZATION             (VMDIR_ERROR_BASE + VMDIR_SCHEMA_ERROR_BASE + 25 )  // 9625

//////////////////////////////////////////////////////////////////////////////////////////////////
// generic backend error (range 9700 - 9799)
//////////////////////////////////////////////////////////////////////////////////////////////////
#define IS_VMDIR_BACKEND_ERROR_SPACE(n) \
    VMDIR_RANGE((n),(VMDIR_ERROR_BASE + VMDIR_BACKEND_ERROR_BASE) , (VMDIR_ERROR_BASE + VMDIR_BACKEND_ERROR_BASE + 99) )

#define VMDIR_ERROR_BACKEND_ERROR                     (VMDIR_ERROR_BASE + VMDIR_BACKEND_ERROR_BASE + 0 )  // 9700
#define VMDIR_ERROR_BACKEND_MAX_RETRY                 (VMDIR_ERROR_BASE + VMDIR_BACKEND_ERROR_BASE + 1 )  // 9701
#define VMDIR_ERROR_BACKEND_DEADLOCK                  (VMDIR_ERROR_BASE + VMDIR_BACKEND_ERROR_BASE + 2 )  // 9702
#define VMDIR_ERROR_BACKEND_ENTRY_NOTFOUND            (VMDIR_ERROR_BASE + VMDIR_BACKEND_ERROR_BASE + 3 )  // 9703
#define VMDIR_ERROR_BACKEND_PARENT_NOTFOUND           (VMDIR_ERROR_BASE + VMDIR_BACKEND_ERROR_BASE + 4 )  // 9704
#define VMDIR_ERROR_BACKEND_CONSTRAINT                (VMDIR_ERROR_BASE + VMDIR_BACKEND_ERROR_BASE + 5 )  // 9705
#define VMDIR_ERROR_BACKEND_ENTRY_EXISTS              (VMDIR_ERROR_BASE + VMDIR_BACKEND_ERROR_BASE + 6 )  // 9706
#define VMDIR_ERROR_BACKEND_OPERATIONS                (VMDIR_ERROR_BASE + VMDIR_BACKEND_ERROR_BASE + 7 )  // 9707
#define VMDIR_ERROR_BACKEND_ATTR_META_DATA_NOTFOUND   (VMDIR_ERROR_BASE + VMDIR_BACKEND_ERROR_BASE + 8 )  // 9708
#define VMDIR_ERROR_BACKEND_INVALID_METADATA          (VMDIR_ERROR_BASE + VMDIR_BACKEND_ERROR_BASE + 9 )  // 9709
#define VMDIR_ERROR_BACKEND_RECORD_NOTFOUND           (VMDIR_ERROR_BASE + VMDIR_BACKEND_ERROR_BASE + 10 ) // 9710

//////////////////////////////////////////////////////////////////////////////////////////////////
// REST server error (range 9900 - 9999)
//////////////////////////////////////////////////////////////////////////////////////////////////
#define IS_VMDIR_REST_ERROR_SPACE(n) \
    VMDIR_RANGE((n),(VMDIR_ERROR_BASE + VMDIR_REST_ERROR_BASE) , (VMDIR_ERROR_BASE + VMDIR_REST_ERROR_BASE + 99) )

#define VMDIR_ERROR_REST_IP_UNKNOWN                   (VMDIR_ERROR_BASE + VMDIR_REST_ERROR_BASE + 0 )     // 9900
#define VMDIR_ERROR_REST_HOSTNAME_UNKNOWN             (VMDIR_ERROR_BASE + VMDIR_REST_ERROR_BASE + 1 )     // 9901

#endif /* __VDIR_ERRORCODE_H__ */
