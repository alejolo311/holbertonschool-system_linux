#include "ls.h"

/**
 * open_dir - open a dir
 * Description: this function validates the argv and try to open the folder
 * in case argv was empty open the execution folder
 * @argc: this argument contains the number of args passed in the call
 * @argv: double pointer to the arguments passed in the call
 * section header: the header of this function is ls.h
 * Return: a valid directory
 */
DIR *open_dir(int argc, char **argv)
{
	DIR *dir;
	(void) argc;
	(void) argv;

	dir = opendir("./");
	return (dir);
}
/**
 * read_dir - entry point of ls program
 * Description: this function read a directory and print the content
 * @dir: directory to read
 * section header: the header of this function is ls.h
 * Return: void
 */
void read_dir(DIR *dir)
{
	struct dirent *read;

	while ((read = readdir(dir)) != NULL)
		if (read->d_name[0] != '.')
			printf("%s  ", read->d_name);
	putchar(10);
}
