#include "plslib.h"

unsigned long _PLS_randseed = 1;

int plsrand(void){
    _PLS_randseed = _PLS_randseed * 1103515245 + 12345;
    return ((unsigned int)(_PLS_randseed >> 16) & PLS_RAND_MAX);
}