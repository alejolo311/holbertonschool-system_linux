#include "laps.h"
/**
 * race_state - function to print the state of the race
 * Description: update the state the race and printed
 * @id: the cars id
 * @size: the number of cars
 * section header: the header of this function is lapś.h
 * Return: void
 */
void race_state(int *id, size_t size)
{
	size_t i;
	Car *_car;

	static Car *head;

	if (size == 0)
	{
		while (head == NULL)
		{
			_car = head;
			head = head->next;
			free(_car);
		}
		return;
	}
	for (i = 0; i < size; i++)
		new_car(&head, id[i]);

	printf("Race state:\n");
	for (_car = head; _car != NULL; _car = _car->next)
		printf("Car %d [%lu laps]\n", _car->id, _car->laps);

}

/**
 * new_car - add a new car to the race
 * Description: add a new car to the race
 * @head: the head of the linked list
 * @id: the id of the new car to add
 * section header: the header of this function is laps.h
 * Return: void
 */
void new_car(Car **head, int id)
{
	Car *_car, *t_car;

	if (*head == NULL || id < (*head)->id)
	{
		_car = malloc(sizeof(Car));
		if (_car == NULL)
			exit(EXIT_FAILURE);
		_car->id = id;
		_car->laps = 0;
		_car->next = *head;
		*head = _car;
		printf("Car %d joined the race\n", id);
		return;
	}
	_car = *head;
	while (_car->next && _car->next->id <= id)
		_car = _car->next;
	if (_car->id == id)
	{
		_car->laps++;
		return;
	}
	t_car = malloc(sizeof(Car));
	if (t_car == NULL)
		exit(EXIT_FAILURE);
	t_car->id = id;
	t_car->laps = 0;
	t_car->next = _car->next;
	_car->next = t_car;
	printf("Car %d joined the race\n", id);
}
