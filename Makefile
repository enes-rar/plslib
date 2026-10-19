ifeq ($(OS), Windows_NT)
	CFLAGS += -DBUILDING_WITH_MAKEFILE
	LDFLAGS += -lkernel32 -lshell32 -lbcrypt
endif

all:
	gcc main.c plsmalloc.c plsrand_t.c plsrand.c plssrand.c $(CFLAGS) $(LDFLAGS) -nostdlib -fno-leading-underscore -std=c89 -Wextra -Wall -Werror -o pro.exe
