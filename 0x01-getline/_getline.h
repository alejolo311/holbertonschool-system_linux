#ifndef GETLINE_H
#define GETLINE_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>


/**
 * struct fd - holds an open file descriptor buffer
 * @fd: the integer file descriptor
 * @vuf: buffer
 * @i: index
 * @len: lenght of the vuf
 * @next: next node
 */
typedef struct fd
{
	int fd;
	char *vuf;
	size_t i;
	size_t len;
	struct fd *next;
} vuffer;


char *_getline(const int fd);
char *read_line(vuffer *fb);
char *get_line(vuffer *head, const int fd);
void end_of_file(vuffer *head);
char *find_char(char *s, char c, ssize_t size);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);

#endif /* GETLINE_H */
