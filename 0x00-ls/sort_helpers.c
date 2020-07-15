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
 * menv - this function convert a list to a doble pointer
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
	files = calloc(i +1, sizeof(char *));
	h = *head;
	for (i = 0; h; i++, h = h->next)
		files[i] = strdup(h->var);
	return (files);
}
/**
 * insertion_sort_list - insertion sort algorithm
 * Description: insertion sort algorithm
 * @list: list
 * Return: void
 */
void nsort(lfile_s **list)
{
	lfile_s *aux, *tail, *head, *swap_1, *swap_2, *aux_1, *aux_2;

	if (list == NULL || *list == NULL)
		return;
	head = *list;
	while (head != NULL && head->next != NULL)
	{	
		if (head->var[0] > head->next->var[0])
		{

			swap_1 = head, swap_2 = head->next;
			aux_1 = swap_1->prev, aux_2 = swap_2->next;
			if (aux_1 != NULL)
				aux_1->next = swap_2;
			else
				*list = swap_2;
			aux_2 != NULL ? aux_2->prev = swap_1 : aux_2;
			swap_2->prev = aux_1, swap_1->next = aux_2;
			swap_2->next = swap_1, swap_1->prev = swap_2;
			tail = head, head = head->prev;
			while (head && head->prev)
			{ aux = head;
				if (aux->var[0]  < aux->prev->var[0] )
				{
					swap_1 = aux->prev, swap_2 = aux;
					aux_1 = swap_1->prev, aux_2 = swap_2->next;
					if (aux_1 != NULL)
						aux_1->next = swap_2;
					else
						*list = swap_2;
					aux_2 != NULL ? aux_2->prev = swap_1 : aux_2;
					swap_2->prev = aux_1, swap_1->next = aux_2;
					swap_2->next = swap_1, swap_1->prev = swap_2;
				}
				else
					break;
			} head = tail;
		} else
			head = head->next;
	}
}
void reverse(lfile_s **head) 
{ 
	lfile_s *temp = NULL;   
	lfile_s *current = *head; 
	while (current !=  NULL) 
	{ 
	   temp = current->prev; 
	   current->prev = current->next; 
	   current->next = temp;               
	   current = current->prev; 
 	}       
	if(temp != NULL) 
		*head = temp->prev; 
}   