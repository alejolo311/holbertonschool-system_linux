#include "ls.h"
/**
 * to_list - this function creat a list from **pointer
 * @files: the double pointer to convert
 * Description: this funtion create a list from a double pointer
 * section header: the header of this function is ls.h
 * Return: return the list.
 **/
lfile_s *to_list(char **files, char *folder)
{
	int i;
	lfile_s *lfile;
	struct stat file;
	char buffer[48];

	lfile = NULL;
	for (i = 0; files[i] != NULL; i++)
	{
		sprintf(buffer, "%s/%s", folder, files[i]);
		if (lstat(buffer, &file) == -1)
		{
			perror("lstat");
			exit(EXIT_FAILURE);
		}
		add_node(&lfile, files[i], file);
		free(files[i]);
	}
	free(files);
	return (lfile);

}
/**
 * to_array - this function convert a list to a doble pointer
 * @head: the head of list
 * Description: this converts list to a doble pointer.
 * section header: the header of this function is ls.h
 * Return: the doble pointer.
 **/
char **to_array(lfile_s **head)
{
	int i;
	lfile_s *h = *head;
	char **files;

	for (i = 0; h; i++)
		h = h->next;
	files = _calloc(i + 1, sizeof(char *));
	h = *head;
	for (i = 0; h; i++, h = h->next)
		files[i] = _strdup(h->var);
	return (files);
}
