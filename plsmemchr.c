#include "plsdef.h"

void *memchr(const void* ptr, int ch, size_t count){
    const unsigned char s1 = (unsigned char)ch; 
    const unsigned char* s2 = (unsigned char*)ptr;

    while(0 < count){
        while(*s2 == s1){
            return ((void*)s2);
        }
    --count;
    ++s2;
    }

return NULL;
}

/* WRITE BCMP */