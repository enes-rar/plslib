typedef char ____UNSAFE_COMP[(1 << 1 == 2) ? 1 : -1]; /* FIX LATER (MOVE TO ENTRY), compiler check */

#ifndef __PLSOSMACROS
#define __PLSOSMACROS__ 1

#if defined(_WIN32)
    #define _Uintptrt unsigned long long

    #define ____FOPEN_SL 16 /* max file opened simul soft limit*/

    #define HEAP_NO_SERIALIZE 0x00000001 /* heapalloc threads */
    #define HEAP_GENERATE_EXCEPTIONS 0x00000004 /* heapalloc will raise exceptions instead of returning null directly */
    #define HEAP_ZERO_MEMORY 0x00000008 /* heapalloc will zero initialize directly */

    #define FORMAT_MESSAGE_FROM_SYSTEM 0x00001000
    #define FORMAT_MESSAGE_IGNORE_INSERTS 0x00000200 /* formatmessage remove optionals */
    #define FORMAT_MESSAGE_FROM_HMODULE 0x00000800 /* formatmessage fallback if no message in system */
    #define ____FORMAT_DEF FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS | FORMAT_MESSAGE_FROM_HMODULE

    #define BCRYPT_RNG_ALG_HANDLE (void **)0x00000081 /* FIX LATER (WIN8 COMP), windows crypto rng */
    #define BCRYPT_RNG_ALGORITHM L"RNG" /* FIX LATER (WIN8 COMP), windows crypto rng */

    #define STD_INPUT_HANDLE ((DWORD)-10)
    #define STD_OUTPUT_HANDLE ((DWORD)-11)
    #define STD_ERROR_HANDLE ((DWORD)-12)

#endif /* win */

#endif /* __PLSUSER__ */