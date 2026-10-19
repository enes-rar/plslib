#include "plsint.h"

uintptr_t __stack_chk_guard = 0;

__attribute__((noreturn)) void __stack_chk_fail(void){
    ExitProcess(1);
}

__attribute__((no_stack_protector)) void init_stack_canary(void){
    uintptr_t rand_val = (uintptr_t)plsrand_t();
    __stack_chk_guard = rand_val & ~((uintptr_t)0xFF);

}
