ifeq ($(OS), Windows_NT)
	CFLAGS += -DBUILDING_WITH_MAKEFILE
	LDFLAGS += -lkernel32 -lshell32 -lbcrypt
endif

all:
	gcc plsrun.c ssp.c plsmemchr.c plsmemcmp.c plsmemcpy.c plsmalloc.c plsrand_t.c plsrand.c plssrand.c -lgcc -nostdlib -ffreestanding -fstack-protector-strong -fno-builtin -std=c89 -fuse-ld=lld $(CFLAGS) $(LDFLAGS) -o renew.exe
