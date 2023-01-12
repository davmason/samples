// Licensed to the .NET Foundation under one or more agreements.
// The .NET Foundation licenses this file to you under the MIT license.
// See the LICENSE file in the project root for more information.

#pragma once

#ifndef WIN32
#include <cstdlib>

#define interface struct

#define WCHAR(str) u##str

#define CoTaskMemAlloc(cb) malloc(cb)
#define CoTaskMemFree(cb) free(cb)

#define UINT_PTR_FORMAT "lx"

#define PROFILER_STUB __attribute__((visibility("hidden"))) EXTERN_C void STDMETHODCALLTYPE

typedef void VOID;

typedef int LONG;       // NOTE: diff from windows.h, for LP64 compat
typedef unsigned int ULONG; // NOTE: diff from windows.h, for LP64 compat

typedef __int64 LONGLONG;
typedef unsigned __int64 ULONGLONG;
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
typedef CONST void *LPCVOID;
typedef int INT;
typedef unsigned int UINT;
typedef unsigned int *PUINT;
typedef BYTE BOOLEAN;
typedef BOOLEAN *PBOOLEAN;

typedef unsigned __int8 UINT8;
typedef signed __int8 INT8;
typedef unsigned __int16 UINT16;
typedef signed __int16 INT16;
typedef unsigned __int32 UINT32, *PUINT32;
typedef signed __int32 INT32, *PINT32;
typedef unsigned __int64 UINT64, *PUINT64;
typedef signed __int64 INT64, *PINT64;

typedef unsigned __int32 ULONG32, *PULONG32;
typedef signed __int32 LONG32, *PLONG32;
typedef unsigned __int64 ULONG64;
typedef signed __int64 LONG64;


typedef VOID *HANDLE;
typedef HANDLE HWND;
typedef struct __PAL_RemoteHandle__ { HANDLE h; } *RHANDLE;
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

#else
#define WCHAR(str) L##str
#define PROFILER_STUB EXTERN_C void STDMETHODCALLTYPE
#define UINT_PTR_FORMAT "llx"
#endif
