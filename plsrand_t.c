#include "plslib.h"
#include "plsosmacros.h"

int plsrand_t(void){
    return BCryptOpenAlgorithmProvider(BCRYPT_RNG_ALG_HANDLE, BCRYPT_RNG_ALGORITHM, NULL, 0);
}