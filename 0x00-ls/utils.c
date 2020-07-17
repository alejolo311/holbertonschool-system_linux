#include "ls.h"
/**
 * include - read the argv and select the valid args
 * Description: this function validates the argv and return the valid arguments
 * @valid: this argument contains the number of args passed in the call
 * @arg: double pointer to the arguments passed in the call
 * section header: the header of this function is ls.h
 * Return: true if the arg is valid, otherwise false
 */
bool include(char *valid, char arg)
{
	int i;

	for (i = 0; i < _strlen(valid); i++)
	{
		if (valid[i] == arg)
			return (true);
	}
	return (false);
}
/**
 * permissions - read the permissions in struct mode and format
 * Description: format the permissions
 * @file: the struct that contains the info of a file
 * section header: the header of this function is ls.h
 * Return: a format permissions string
 */
char *permissions(struct stat file)
{
		char *permissions = malloc(sizeof(char) * 11);
		mode_t perm = file.st_mode;

		permissions[0] = ((perm & S_IFMT) == S_IFDIR) ? 'd' : '-';
		permissions[1] = (perm & S_IRUSR) ? 'r' : '-';
		permissions[2] = (perm & S_IWUSR) ? 'w' : '-';
		permissions[3] = (perm & S_IXUSR) ? 'x' : '-';
		permissions[4] = (perm & S_IRGRP) ? 'r' : '-';
		permissions[5] = (perm & S_IWGRP) ? 'w' : '-';
		permissions[6] = (perm & S_IXGRP) ? 'x' : '-';
		permissions[7] = (perm & S_IROTH) ? 'r' : '-';
		permissions[8] = (perm & S_IWOTH) ? 'w' : '-';
		permissions[9] = (perm & S_IXOTH) ? 'x' : '-';
		permissions[10] = '\0';
		return (permissions);
}
/**
 * get_date - obtain the date
 * Description: parse the date provide by ctime
 * @file: the struct that contains the info of a file
 * section header: the header of this function is ls.h
 * Return: a format string with date
 */
char *get_date(struct stat file)
{
	char *date = _strdup(ctime(&file.st_mtime));
	char buffer[48];


	sprintf(buffer, "%c%c%c %c%c %c%c:%c%c",
					date[4], date[5], date[6], date[8], date[9],
					date[11], date[12], date[14], date[15]);
	free(date);
	date = _strdup(buffer);
	return (date);
}
/**
 * get_nodes - get the alloc blocks
 * Description: obtain the number of alloc blocks in folder
 * @files: all the files in a folder
 * @folder: the folder thath containes the fail
 * section header: the header of this function is ls.h
 * Return: a int with quantity or 0 if is the case
 */
int get_nodes(char **files, char *folder)
{

	struct stat file;
	int i = 0;
	long int nodes = 0;
	char buffer[48];

	for (i = 0; files[i] != NULL; i++)
	{
		sprintf(buffer, "%s/%s", folder, files[i]);
		if (lstat(buffer, &file) == -1)
		{
			perror("lstat");
			exit(EXIT_FAILURE);
		}
		if (files[i][0] != '.')
			nodes += ((long) file.st_blocks / 2);
	}
	return (nodes);
}
