CC = gcc
CFLAGS = #-Wall -Werror -Wextra -pedantic

strace_0: 0-strace.o libutils.a
	gcc -lm -o strace_0 0-strace.o -L. -lutils

strace_1: 1-strace.o libutils.a
	gcc -lm -o strace_1 1-strace.o -L. -lutils

strace_2: 2-strace.o libutils.a
	gcc -lm -o strace_2 2-strace.o -L. -lutils

libutils.a: lib.o
	ar rcu $@ $+
	ranlib $@