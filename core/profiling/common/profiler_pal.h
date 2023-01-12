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
typedef int LONG;
typedef int BOOL;
typedef unsigned char BYTE;
typedef unsigned __int32 ULONG32, *PULONG32;
typedef signed __int32 LONG32, *PLONG32;
typedef unsigned __int64 ULONG64;
typedef signed __int64 LONG64;

typedef LONG HRESULT;

#else
#define WCHAR(str) L##str
#define PROFILER_STUB EXTERN_C void STDMETHODCALLTYPE
#define UINT_PTR_FORMAT "llx"
#endif
