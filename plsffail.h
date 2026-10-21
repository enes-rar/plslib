#ifndef __PLSFFAIL__
#define __PLSFFAIL__ 1

#define FAST_FAIL_STACK_COOKIE_CHECK_FAILURE 2

#if defined(__GNUC__)
    #define __pls_unreachable() (__builtin_unreachable())
#endif /* unreachable */

__attribute__((noreturn, always_inline, no_stack_protector)) static __inline__ void __pls_fastfail_64(unsigned int code){
    __asm__ __volatile__(
        "int $0x29"
        :
        :"c"(code)
        :"memory"
    );
    __pls_unreachable();
}

#endif /* __PLSFFAIL__ */