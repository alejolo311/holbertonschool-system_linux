#include "strace.h"

/**
 * main - Entry Point
 * @argc : # of args
 * @argv: ** args
 * @env: enviroment
 * Return: succes or fail
 */
int main(int argc, char **argv, char **env)
{
	pid_t pid;

	if (argc < 2)
		printf("Usage: %s command [args...]\n", *(argv + 0));
	else
	{
		pid = fork();
		if (pid == 0)
		{
			trace(argv + 1, env);
		} else if (pid > 0)
		{
			tracer(pid);
		} else
		{
			perror("fork failed");
			exit(EXIT_FAILURE);
		}
	}
	return (EXIT_SUCCESS);
}
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
void tracer(pid_t pid)
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
		printf("%ld\n", (size_t) registers.orig_rax);
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

