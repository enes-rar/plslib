# plslib

standard library for x86-64 windows 11-10 gcc/clang/msvc(partial)

## plscanary.h
Gives protection for buffer overflow. Makefile has the flag -fstack-protector-strong on default.

## plsdef.h
size_t: Holds the theoretical maximum size of any type. e.g. sizeof returns size_t.

NULL: Defined on default as void pointer constant 0. Macro PLS_NULL_NOCAST can be used to define it as integer constant 0.

## plsint.h
uintptr_t: Unsigned integer type capable of holding a pointer to void.

## plslib.h
void plssrand(unsigned int seed): Set the seed for the PRNG function plsrand.

int plsrand(void): PRNG function.

int plsrand_t(void): High entropy RNG function. (Uses Windows' Crpyto API)

void* plsmalloc(size_t size): Allocates size bytes of uninitialized storage. If passed 0 with the macro PLS_MALLOC_SIZE0_NULL returns 0, with the macro PLS_MALLOC_SIZE0_FREE returns a pointer that may be freed, with no macros set refers to platform's default.

## plswintypes.h
Can be used for Windows API functions.

## Runtime
argc and argv are pushed as optional arguments to main. int/void main(void), (int argc), (int argc, char** argv) are all valid signatures, but the return type being int is preferred over void.
