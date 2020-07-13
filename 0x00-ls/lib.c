#include "ls.h"
/**
 * validate_dir - read the argv and select the folders
 * Description: this function validates the argv and return the valid folders
 * @argc: this argument contains the number of args passed in the call
 * @argv: double pointer to the arguments passed in the call
 * @ret: is the value of return in normal cases 0 in error 2
 * @fcount: is the count of folders that ls recieves as an arg
 * section header: the header of this function is ls.h
 * Return: a double pointer that contains all the valid folders
 */
char **validate_dir(int argc, char **argv, int *ret, int *fcount)
{
	char **folders = NULL;
	int i = 0, j = 0;
	struct stat sb;

	if (argc != 1)
	{
		folders = malloc(sizeof(*folders) * argc);
		if (folders == NULL)
			return (NULL);
		for (i = 1, j = 0; argv[i] != NULL; i++, j++)
		{
			if (stat(argv[i], &sb) == 0 && S_ISDIR(sb.st_mode))
				folders[j] = strdup(argv[i]), (*fcount)++;
			else
			{
				fprintf(stderr,
						"hls: cannot access '%s': No such file or directory\n",
						argv[i]);
				(*ret) = 2;
				j--;
			}
		}
	}
	else
		return (NULL);

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
	if (dir)
		return (dir);
	else
		return (NULL);

}
/**
 * read_dir - entry point of ls program
 * Description: this function read a directory and print the content
 * @dir: directory to read
 * @folder: the name of the folder
 * @argc: this argument contains the number of args passed in the call
 * @ret: is the value of return in normal cases 0 in error 2
 * @errors: a double pointer that stores the names of the folder with errors
 * section header: the header of this function is ls.h
 * Return: void
 */
void read_dir(DIR *dir, char *folder, int argc, int *ret, char **errors)
{

	struct stat sb;
	struct dirent *read;
	int i;

	if (stat(folder, &sb) == 0 && sb.st_mode & S_IRUSR)
	{
		argc > 2 ? printf("%s:\n", folder) : argc;
		while ((read = readdir(dir)) != NULL)
			if (read->d_name[0] != '.')
				printf("%s  ", read->d_name);
		putchar(10);
	}
	else
	{
		for (i = 0; *(errors + i); i++)
		{
		}
		*(errors + i) = strdup(folder);
		*(ret) = 3;
	}
}
