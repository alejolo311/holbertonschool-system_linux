CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic

strace_0: 0-strace.o libutils.a
	gcc -lm -o strace_0 0-strace.o -L. -lutils

libutils.a: lib.o
	ar rcu $@ $+
	ranlib $@

strace_1:
	$(CC) $(CFLAGS) 1-strace.c  lib.c -o strace_1

