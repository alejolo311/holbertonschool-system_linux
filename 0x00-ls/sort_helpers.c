#include "ls.h"
/**
 * to_list - this function creat a list from **pointer
 * @files: the double pointer to convert
 * Description: this funtion create a list from a double pointer
 * section header: the header of this function is ls.h
 * Return: return the list.
 **/
lfile_s *to_list(char **files)
{
	int i;
	lfile_s *lfile;

	lfile = NULL;
	for (i = 0; files[i] != NULL; i++)
	{
		add_node(&lfile, files[i]);
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
/**
 * reverse - this function convert a list to a doble pointer
 * @head: the head of list
 * Description: this converts list to a doble pointer.
 * section header: the header of this function is ls.h
 * Return: the doble pointer.
 **/
void reverse(lfile_s **head)
{
	lfile_s *temp = NULL;
	lfile_s *current = *head;

	while (current != NULL)
	{
		temp = current->prev;
		current->prev = current->next;
		current->next = temp;
		current = current->prev;
	}
	if (temp != NULL)
		*head = temp->prev;
}
