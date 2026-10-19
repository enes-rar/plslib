#ifndef __WINTYPES__
#define __WINTYPES__ 1

typedef char CHAR;
typedef unsigned char UCHAR;
typedef unsigned short WCHAR;

typedef UCHAR* PUCHAR;

typedef WCHAR* LPWSTR;
typedef const WCHAR* LPCWSTR;
typedef char* LPSTR;

#if defined(UNICODE)
    typedef LPWSTR LPTSTR;
#else
    typedef LPSTR LPTSTR;
#endif

typedef void* PVOID;
typedef void* LPVOID;
typedef const void* LPCVOID;

typedef PVOID HANDLE;
typedef HANDLE HLOCAL;

#if defined(_WIN64)
    typedef long long LONG_PTR;
    typedef unsigned long long ULONG_PTR;
    typedef unsigned long long _Uintptrt;
#else
    typedef long LONG_PTR;
    typedef unsigned long ULONG_PTR;
#endif

typedef unsigned long DWORD;
typedef unsigned long ULONG;

typedef DWORD* LPDWORD;

typedef long NTSTATUS; /* FIX LATER (SAL ANNO) */

typedef PVOID BCRYPT_ALG_HANDLE;

typedef struct _OVERLAPPED {
  ULONG_PTR Internal;
  ULONG_PTR InternalHigh;
  union {
    struct {
      DWORD Offset;
      DWORD OffsetHigh;
    } DUMMYSTRUCTNAME;
    PVOID Pointer;
  } DUMMYUNIONNAME;
  HANDLE    hEvent;
} OVERLAPPED, *LPOVERLAPPED;

#define WINAPI __stdcall

#endif /* __WINTYPES__ */
