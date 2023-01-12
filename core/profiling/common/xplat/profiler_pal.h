// Licensed to the .NET Foundation under one or more agreements.
// The .NET Foundation licenses this file to you under the MIT license.
// See the LICENSE file in the project root for more information.

#pragma once

#ifndef WIN32
#include <cstdlib>
#include <cinttypes>

#define EXTERN_C extern "C"
#define __stdcall
#define interface struct

#define WCHAR(str) u##str

#define CoTaskMemAlloc(cb) malloc(cb)
#define CoTaskMemFree(cb) free(cb)

#define UINT_PTR_FORMAT "lx"

#define STDMETHODCALLTYPE

#define PROFILER_STUB __attribute__((visibility("hidden"))) EXTERN_C void STDMETHODCALLTYPE

typedef void VOID;

typedef char16_t WCHAR;
typedef int LONG;
typedef unsigned int ULONG;
typedef intptr_t INT_PTR;
typedef uintptr_t UINT_PTR;
typedef size_t SIZE_T;

typedef int64_t LONGLONG;
typedef uint64_t ULONGLONG;
typedef ULONGLONG DWORD64;
typedef DWORD64 *PDWORD64;
typedef LONGLONG *PLONG64;
typedef ULONGLONG *PULONG64;
typedef ULONGLONG *PULONGLONG;
typedef ULONG *PULONG;
typedef short SHORT;
typedef SHORT *PSHORT;
typedef unsigned short USHORT;
typedef USHORT *PUSHORT;
typedef unsigned char UCHAR;
typedef UCHAR *PUCHAR;
typedef char *PSZ;
typedef ULONGLONG DWORDLONG;

typedef unsigned int DWORD; // NOTE: diff from  windows.h, for LP64 compat
typedef unsigned int DWORD32, *PDWORD32;

typedef int BOOL;
typedef unsigned char BYTE;
typedef unsigned short WORD;
typedef float FLOAT;
typedef double DOUBLE;
typedef BOOL *PBOOL;
typedef BOOL *LPBOOL;
typedef BYTE *PBYTE;
typedef BYTE *LPBYTE;
typedef const BYTE *LPCBYTE;
typedef int *PINT;
typedef int *LPINT;
typedef WORD *PWORD;
typedef WORD *LPWORD;
typedef LONG *LPLONG;
typedef LPLONG PLONG;
typedef DWORD *PDWORD;
typedef DWORD *LPDWORD;
typedef void *PVOID;
typedef void *LPVOID;
typedef const void *LPCVOID;
typedef int INT;
typedef unsigned int UINT;
typedef unsigned int *PUINT;
typedef BYTE BOOLEAN;
typedef BOOLEAN *PBOOLEAN;

typedef uint8_t UINT8;
typedef int8_t INT8;
typedef uint16_t UINT16;
typedef int16_t INT16;
typedef uint32_t UINT32, *PUINT32;
typedef int32_t INT32, *PINT32;
typedef uint64_t UINT64, *PUINT64;
typedef int64_t INT64, *PINT64;

typedef uint32_t ULONG32, *PULONG32;
typedef int32_t LONG32, *PLONG32;
typedef uint64_t ULONG64;
typedef int64_t LONG64;

typedef WCHAR *PWCHAR;
typedef WCHAR *LPWCH, *PWCH;
typedef const WCHAR *LPCWCH, *PCWCH;
typedef WCHAR *NWPSTR;
typedef WCHAR *LPWSTR, *PWSTR;

typedef const WCHAR *LPCWSTR, *PCWSTR;

typedef VOID *HANDLE;
typedef HANDLE HWND;
typedef HANDLE *PHANDLE;
typedef HANDLE *LPHANDLE;
#define INVALID_HANDLE_VALUE ((VOID *)(-1))
#define INVALID_FILE_SIZE ((DWORD)0xFFFFFFFF)
#define INVALID_FILE_ATTRIBUTES ((DWORD) -1)
typedef HANDLE HMODULE;
typedef HANDLE HINSTANCE;
typedef HANDLE HGLOBAL;
typedef HANDLE HLOCAL;
typedef HANDLE HRSRC;

typedef LONG HRESULT;
typedef LONG NTSTATUS;

#ifndef GUID_DEFINED
typedef struct _GUID {
    ULONG   Data1;    // NOTE: diff from Win32, for LP64
    USHORT  Data2;
    USHORT  Data3;
    UCHAR   Data4[ 8 ];
} GUID;
typedef const GUID *LPCGUID;
#define GUID_DEFINED
#endif // !GUID_DEFINED

#ifndef __IID_DEFINED__
#define __IID_DEFINED__

typedef struct _IID
{
    unsigned long x;
    unsigned short s1;
    unsigned short s2;
    unsigned char  c[8];
} IID;

#endif // __IID_DEFINED__

#ifndef CLSID_DEFINED
#define CLSID_DEFINED
typedef IID CLSID;
#endif // CLSID_DEFINED

#define REFGUID const GUID &
#define REFIID const IID &

typedef LONG32 mdToken;
typedef mdToken mdModule;
typedef mdToken mdTypeDef;
typedef mdToken mdMethodDef;
typedef mdToken mdFieldDef;
typedef ULONG CorElementType;

typedef struct
{
	DWORD dwOSPlatformId;
	DWORD dwOSMajorVersion;
	DWORD dwOSMinorVersion;
} OSINFO;

typedef struct
{
    USHORT usMajorVersion;
    USHORT usMinorVersion;
    USHORT usBuildNumber;
    USHORT usRevisionNumber;
    LPWSTR szLocale;
    ULONG cbLocale;
    DWORD *rProcessor;
    ULONG ulProcessor;
    OSINFO *rOS;
    ULONG ulOS;
} ASSEMBLYMETADATA;

#else
#define WCHAR(str) L##str
#define PROFILER_STUB EXTERN_C void STDMETHODCALLTYPE
#define UINT_PTR_FORMAT "llx"
#endif
