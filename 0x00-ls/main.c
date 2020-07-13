#include "ls.h"
/**
 * main - entry point of ls program
 * Description: this function try to replicate as close as possible
 * the real behavior of the ls function present in linux
 * @argc: this argument contains the number of args passed in the call
 * @argv: double pointer to the arguments passed in the call
 * section header: the header of this function is ls.h
 * Return: 0 in success, for other codes of error read the documentation
 */
int main(int argc, char **argv)
{
	DIR *dir;
	char **dirs;


	dirs = validate_dir(argc, argv);
	for (int i = 0; dirs[i] != NULL; i++)
	{
		i != 0 ? putchar(10) : i;
		printf("%s:\n", dirs[i]);
		dir = open_dir(dirs[i]);
		read_dir(dir);
		closedir(dir);

	}
	return (0);
}
