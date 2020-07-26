#ifndef LAPS_H
#define LAPS_H

#include <stdio.h>
#include <stdlib.h>
/**
 * struct car - singly linked list to store the cars present in the race
 * @id: id of the car
 * @laps: number of the laps completed by the car
 * @next: the next cat
 * Description: singly linked list node to store cars
 */
typedef struct car
{
	int id;
	size_t laps;
	struct car *next;
} Car;

void race_state(int *id, size_t size);
void new_car(Car **head, int id);

#endif /* LAPS_H */
