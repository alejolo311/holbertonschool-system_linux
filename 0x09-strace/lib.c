#include "strace.h"

/**
 * trace - run tracee
 * @argv: args to execute
 * @env: env
 */
void trace(char **argv, char **env)
{
	if (ptrace(PTRACE_TRACEME, 0, 0, 0) < 0)
	{
		perror("Error setting TRACEME");
		exit(EXIT_FAILURE);
	}
	kill(getpid(), SIGSTOP);
	execve(*(argv + 0), argv, env);
}
/**
 * tracer -  run tracer
 * @pid: to trace
 */
void tracer(pid_t pid, int method)
{
	struct user_regs_struct registers;
	int status;

	waitpid(pid, &status, 0);
	ptrace(PTRACE_SETOPTIONS, pid, 0, PTRACE_O_TRACESYSGOOD);
	while (1)
	{
		if (_syscallWait(pid) != 0)
			break;
		ptrace(PTRACE_GETREGS, pid, 0, &registers);
        if (method == 1)
		    printf("%ld\n", (size_t) registers.orig_rax);
        if (method == 2)
        {
		    printf("%s", syscalls_64_g[(size_t) registers.orig_rax].name);
            printf("\n");
        }
		fflush(stdout);

		if (_syscallWait(pid) != 0)
			break;
	}
}

/**
 * _syscallWait -  trap syscall
 * @pid: pid to trace
 * Return: 1 if sycall was captured
 */
int _syscallWait(pid_t pid)
{
	int status;

	while (1)
	{
		ptrace(PTRACE_SYSCALL, pid, 0, 0);
		waitpid(pid, &status, 0);
		if (WIFSTOPPED(status) && WSTOPSIG(status) & 0x80)
			return (0);
		if (WIFEXITED(status))
			return (1);
	}
}

