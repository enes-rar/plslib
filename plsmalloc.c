#include "plsdef.h"
#include "plsuser.h"
#include "plsdef.h"

void* malloc(size_t size){ /* FIX LATER (ERROR HANDLING, NO COMP), returns free pointer if size = 0 */
    HANDLE ____run_heap = GetProcessHeap();  /* FIX LATER (XP COMP) */
    
    size = (size == 0) ?

        #if defined(PLS_MALLOC_SIZE0_NULL) && !defined(PLS_MALLOC_SIZE0_FREE)
            NULL
        #elif !defined(PLS_MALLOC_SIZE0_NULL) && defined(PLS_MALLOC_SIZE0_FREE)
            1
        #else
            #if defined(_WIN64) 
                1
            #endif /* WIN64 */
        #endif /* malloc size 0 check */

        : size;
        
    return HeapAlloc(____run_heap, 0, size);
}