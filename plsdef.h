#ifndef __PLSDEF__
#define __PLSDEF__ 1

#include "plswintypes.h"

typedef ULONG_PTR size_t;


#if defined(PLS_NULL_NOCAST)
    #define NULL 0
#else
    #define NULL ((void*)0)
#endif /* null void pointer cast */

#endif /* __PLSDEF__ */