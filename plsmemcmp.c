#include "plsdef.h"

int memcmp(const void* lhs, const void* rhs, size_t count){
    const unsigned char *s1 = (unsigned char*)lhs; 
    const unsigned char *s2 = (unsigned char*)rhs;
    unsigned char x, y;

    while(0 < count){
        x = *s1;
        y = *s2;

        if(x != y){
            return ((x < y) ? -1 : 1);
        }

        --count;
        ++s1;
        ++s2;
    }

return 0;
}