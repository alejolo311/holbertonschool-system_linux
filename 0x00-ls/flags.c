#include "ls.h"
/**
 * flag_l - function to manage the "l" flag
 * Description: print in long format
 * @files: the files that the folder contains
 * @folder: the folder that is print
 * section header: the header of this function is ls.h
 * Return: void
 */
void flag_l(char **files, char *folder)
{
	struct stat file;
	int nodes, i;
	char buffer[48];
	struct passwd *usr;
	struct group *grp;
	char *perm, *date;

	nodes = get_nodes(files, folder);
	printf("total %i\n", nodes);

	for (i = 0; files[i] != NULL; i++)
	{
		sprintf(buffer, "%s/%s", folder, files[i]);

		if (lstat(buffer, &file) == -1)
		{
			perror("lstat");
			exit(EXIT_FAILURE);
		}
		usr = getpwuid(file.st_uid);
		grp = getgrgid(file.st_gid);
		perm = permissions(file);
		date = get_date(file);

		if (files[i][0] != '.')
		{
			printf("%s ", perm);
			printf("%ld ", (long) file.st_nlink);
			printf("%s ", usr->pw_name);
			printf("%s ", grp->gr_name);
			printf("%5lld ", (long long) file.st_size);
			printf("%s ", date);
			printf("%s\n", files[i]);
			free(files[i]);
		}
	}
	free(files);
}
/**
 * flag_a - function to manage the "a" flag
 * Description: print hide things
 * @files: the files that the folder contains
 * @folder: the folder that is print
 * section header: the header of this function is ls.h
 * Return: void
 */
void flag_a(char **files, char *folder)
{
	int i;
	(void) folder;

	for (i = 0; files[i] != NULL; i++)
		printf("%s  ", files[i]), free(files[i]);
	putchar(10);
	free(files);
}
/**
 * flag_A - function to manage the "A" flag
 * Description: print hide things with exceptions
 * @files: the files that the folder contains
 * @folder: the folder that is print
 * section header: the header of this function is ls.h
 * Return: void
 */
void flag_A(char **files, char *folder)
{
	int i;
	(void) folder;

	for (i = 0; files[i] != NULL; i++)
	{
		if (strcmp(files[i], ".") != 0 && strcmp(files[i], "..") != 0)
			printf("%s  ", files[i]);
		free(files[i]);
	}
	putchar(10);
	free(files);
}
/**
 * flag_1 - function to manage the "1" flag
 * Description: print witn /n between each file
 * @files: the files that the folder contains
 * @folder: the folder that is print
 * section header: the header of this function is ls.h
 * Return: void
 */
void flag_1(char **files, char *folder)
{
	int i;
	(void) folder;

	for (i = 0; files[i] != NULL; i++)
	{
		if (files[i][0] != '.')
			printf("%s\n", files[i]);
		free(files[i]);
	}
	free(files);
}
/**
 * without_flags - function to manage the normal print
 * Description: normal ls print
 * @files: the files that the folder contains
 * @folder: the folder that is print
 * section header: the header of this function is ls.h
 * Return: void
 */
void without_flags(char **files, char *folder)
{
	int i;
	(void) folder;

	for (i = 0; files[i] != NULL; i++)
	{
		if (files[i][0] != '.')
			printf("%s  ", files[i]);
		free(files[i]);
	}
	putchar(10);
	free(files);
}
