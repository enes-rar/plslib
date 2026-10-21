#include "plsint.h"
#include "plsffail.h"
#include "plslib.h"
#include "plscanary.h"

uintptr_t __stack_chk_guard = 0;

__attribute__((noreturn)) void __stack_chk_fail(void){
    __pls_fastfail_64(FAST_FAIL_STACK_COOKIE_CHECK_FAILURE);
}

__attribute__((no_stack_protector, noinline)) void init_stack_canary(void){
    uintptr_t rand_val = (uintptr_t)plsrand_t();
    __stack_chk_guard = rand_val & ~((uintptr_t)0xFF);
}
