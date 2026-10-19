#ifndef __PLSLINK__
#define __PLSLINK__ 1

#include "plsdef.h"

#if defined(_WIN32)
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

    __declspec(dllimport) void __stdcall ExitProcess(unsigned int uExitcode); /* kill yourself */
    __declspec(dllimport) LPWSTR __stdcall GetCommandLineW(void); /* unused */
    __declspec(dllimport) LPWSTR* __stdcall CommandLineToArgW(LPCWSTR lpCmdLine, int* pNumArgs); /* unused */
    __declspec(dllimport) HLOCAL __stdcall LocalFree(HLOCAL hMem); /* unused */
    __declspec(dllimport) LPVOID __stdcall HeapAlloc(HANDLE hHeap, DWORD dwFlags, size_t dwBytes); /* malloc */
    __declspec(dllimport) HANDLE __stdcall GetProcessHeap(); /* malloc */
    __declspec(dllimport) DWORD __stdcall GetLastError(DWORD dwFlags, LPCVOID lpSource, DWORD dwMessageId, DWORD dwLanguageId, LPTSTR lpBuffer, DWORD nSize); /* unused */
    __declspec(dllimport) NTSTATUS __stdcall BCryptOpenAlgorithmProvider(BCRYPT_ALG_HANDLE *phAlgorithm, LPCWSTR pszAlgId, LPCWSTR pszImplementation, ULONG dwFlags);
    __declspec(dllimport) HANDLE WINAPI __stdcall GetStdHandle(DWORD nStdHandle); /* FIX LATER (ERR), stream */
    __declspec(dllimport) int __stdcall WriteFile(HANDLE hHandle, LPCVOID lpBuffer, DWORD nNumberOfBytesToWrite, LPDWORD lpNumberOfBytesWritten, LPOVERLAPPED lpOverlapped); /* FIX LATER (WIN7 COMP), stream */
    
#endif /* _WIN32 */

#endif /* __PLSLINK__ */