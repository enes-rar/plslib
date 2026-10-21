#ifndef __PLSCANARY__
#define __PLSCANARY__ 1

#include "plsint.h"

extern uintptr_t __stack_chk_guard;

__attribute__((noreturn)) void __stack_chk_fail(void);
__attribute__((no_stack_protector, noinline)) void init_stack_canary(void);

#endif /* __PLSCANARY__ */