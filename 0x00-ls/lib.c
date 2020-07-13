#include "ls.h"
/**
 * validate_dir - read the argv and select the folders
 * Description: this function validates the argv and return the valid folders
 * @argc: this argument contains the number of args passed in the call
 * @argv: double pointer to the arguments passed in the call
 * section header: the header of this function is ls.h
 * Return: a double pointer that contains all the valid folders
 */
char **validate_dir(int argc, char **argv)
{
	char **folders;
	int i;

	if (argc != 1)
	{
		folders = malloc(sizeof(char *) * argc - 1);
		for (i = 0; i < argc; i++)
			folders[i] = argv[i + 1];
	}
	else
	{
		folders = malloc(sizeof(char *));
		folders[0] = "./";
	}
	return (folders);
}

/**
 * open_dir - open a dir
 * Description: this function validates the argv and try to open the folder
 * in case argv was empty open the execution folder
 * @folder: folder to open
 * section header: the header of this function is ls.h
 * Return: a valid directory
 */
DIR *open_dir(char *folder)
{
	DIR *dir;

	dir = opendir(folder);
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
