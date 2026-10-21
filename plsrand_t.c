#include "plslib.h"
#include "plsoslink.h"

int plsrand_t(void){
    unsigned char buf[32];
    BCryptGenRandom(NULL, buf, 32, 0);
    return 0;
}