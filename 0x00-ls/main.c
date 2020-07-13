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

	dir = open_dir(argc, argv);
	read_dir(dir);
	closedir(dir);
	return (0);
}
