#include "plsuser.h"

unsigned long int __stack_chk_guard = 0;

__attribute__((noreturn)) void __stack_chk_fail(void){
    ExitProcess(1);
}

__attribute__((no_stack_protector)) void init_stack_canary(void){
    unsigned long int rand_val = 0x595e9fbd94fda700ULL;
    __stack_chk_guard = rand_val;

}