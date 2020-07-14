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
	DIR *dir = NULL;
	char **dirs = NULL, **errors = NULL, *args = NULL, **files = NULL;
	int i = 0, ret = 0, fcount = 0;

	errors = calloc(12, sizeof(*errors));
	if (errors == NULL)
		return (-1);

	args = validate_args(argv);
	dirs = validate_dir(argc, argv, &ret, &fcount);
	for (i = 0; i < fcount; i++)
	{
		dir = open_dir(dirs[i]);
		files = read_dir(dir, dirs[i], &ret, &*errors);
		if (files)
			print_dir(files, args, dirs[i]);
		closedir(dir);
		free(dirs[i]);
	}
	free(dirs);
	if (ret == 3)
	{
		for (i = 0; errors[i] != NULL; i++)
			fprintf(stderr,
						"hls: cannot open directory '%s': Permission denied\n",
						errors[i]), free(errors[i]);
		free(errors), ret = 2;
	}
	else
		free(errors);
	free(args);
	return (ret);
}
