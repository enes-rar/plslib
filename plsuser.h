typedef char ____UNSAFE_COMP[(1 << 1 == 2) ? 1 : -1]; /* compiler check */

#ifndef __PLSUSER__
#define __PLSUSER__ 1

#if defined(_WIN32) || defined(_WIN64)
    #if !(defined(BUILDING_WITH_MAKEFILE))
        #if defined(__GNUC__) && !(defined(__clang)) /* no pragma link fallback */
            // #error "gcc windows makefile not found"
        #else /* pragma link fallback */
            #pragma comment (lib, "kernel32.lib")
            #warning "no makefile kernel32 link fallback"
            #pragma comment (lib, "shell32.lib")
            #warning "no makefile shell32 link fallback"
            #pragma comment (lib, "bcrypt.lib") /* FIX LATER (COMP) */
            #warning "no makefile bcrypt link fallback"
        #endif /* link check */
    #endif /* makefile flag */

    #include "plswintypes.h"
    #include "plsdef.h"

    __declspec(dllimport) void __stdcall ExitProcess(unsigned int uExitcode); /* kill yourself */
    __declspec(dllimport) LPWSTR __stdcall GetCommandLineW(void); /* unused */
    __declspec(dllimport) LPWSTR* __stdcall CommandLineToArgW(LPCWSTR lpCmdLine, int* pNumArgs); /* unused */
    __declspec(dllimport) HLOCAL __stdcall LocalFree(HLOCAL hMem); /* unused */
    __declspec(dllimport) LPVOID __stdcall HeapAlloc(HANDLE hHeap, DWORD dwFlags, size_t dwBytes); /* malloc */
    __declspec(dllimport) HANDLE __stdcall GetProcessHeap(); /* malloc */
    __declspec(dllimport) DWORD __stdcall GetLastError(DWORD dwFlags, LPCVOID lpSource, DWORD dwMessageId, DWORD dwLanguageId, LPTSTR lpBuffer, DWORD nSize); /* unused */
    __declspec(dllimport) NTSTATUS __stdcall BCryptOpenAlgorithmProvider(BCRYPT_ALG_HANDLE *phAlgorithm, LPCWSTR pszAlgId, LPCWSTR pszImplementation, ULONG dwFlags);

    #define ____FOPEN_SL 16 /* max file opened simul soft limit*/

    #define HEAP_NO_SERIALIZE 0x00000001 /* heapalloc threads */
    #define HEAP_GENERATE_EXCEPTIONS 0x00000004 /* heapalloc will raise exceptions instead of returning null directly */
    #define HEAP_ZERO_MEMORY 0x00000008 /* heapalloc will zero initialize directly */

    #define FORMAT_MESSAGE_FROM_SYSTEM 0x00001000
    #define FORMAT_MESSAGE_IGNORE_INSERTS 0x00000200 /* formatmessage remove optionals */
    #define FORMAT_MESSAGE_FROM_HMODULE 0x00000800 /* formatmessage fallback if no message in system */
    #define ____FORMAT_DEF FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS | FORMAT_MESSAGE_FROM_HMODULE

    #define BCRYPT_RNG_ALG_HANDLE 0x00000081 /* FIX LATER (WIN8 COMP), windows crypto rng */
    #define BCRYPT_RNG_ALGORITHM L"RNG" /* FIX LATER (WIN8 COMP), windows crypto rng */

#endif /* win */

#endif /* __PLSUSER__ */