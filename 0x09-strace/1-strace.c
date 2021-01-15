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
			tracer(pid, 2);
		} else
		{
			perror("fork failed");
			exit(EXIT_FAILURE);
		}
	}
	return (EXIT_SUCCESS);
}
