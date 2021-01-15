#ifndef strace
#define  strace

#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/ptrace.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <errno.h>
#include <sys/utsname.h>
#include <sys/user.h>
#include <sys/types.h>
#include <sys/mman.h>

#include "syscalls.h"


void trace(char **argv, char **env);
int _syscallWait(pid_t child_pid);
void tracer(pid_t child_pid);

#endif /* strace */
