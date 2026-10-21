#include "plsdef.h"

void* memcpy(void* dest, const void* src, size_t count){
    unsigned char* s1 = (unsigned char*)dest; 
    const unsigned char* s2 = (unsigned char*)src;

    while(0 < count){
        *s1 = *s2;

        --count;
        ++s1;
        ++s2;
    }

    return ((void*)s1);
}