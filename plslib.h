#ifndef __PLSLIB__
#define __PLSLIB__ 1
#include "plsdef.h"
#include "plslib.h"

#define PLS_RAND_MAX 32767

extern unsigned long _PLS_randseed;
void plssrand(unsigned int seed);
int plsrand(void);
int plsrand_t(void);


void* plsmalloc(size_t size); /* FLAGS: / PLS_MALLOC_SIZE0_NULL: return 0 when size = 0 / PLS_MALLOC_SIZE0_FREE: return free pointer when size = 0 / */

#endif /* __PLSLIB__ */