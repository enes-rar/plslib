ifeq ($(OS), Windows_NT)
	CFLAGS += -DBUILDING_WITH_MAKEFILE
	LDFLAGS += -lkernel32 -lshell32 -lbcrypt
endif

all:
	gcc $(CFLAGS) $(LDFLAGS) main.c -nostdlib -std=c89 -Wextra -Wall -Werror -o program.exe
