#include "_getline.h"
/**
 * _getline - duplicate of getline
 * Description: geline of a fd
 * @fd: the file descriptor
 * section header: the header of this function is _getline.h
 * Return: char* with the line or null
 */
char *_getline(const int fd)
{
	char *line = NULL;

	static vuffer head;

	if (fd == -1)
	{
		end_of_file(&head);
		return (NULL);
	}
	line = get_line(&head, fd);
	if (line != NULL && line[0] == '\n' && !line[1])
		line[0] = 0;
	return (line);
}
/**
 * get_line - getline helper
 * Description: manage the buffer and call the readline
 * @head: the head of the vuffer
 * @fd: the filedescrioptor
 * section header: the header of this function is _getline.h
 * Return: char the line
 */
char *get_line(vuffer *head, const int fd)
{
	vuffer *_fd;

	if (head->vuf == NULL && head->fd == 0 && head->next == NULL)
	{
		head->fd = fd;
		return (read_line(head));
	}
	while (head->next && head->next->fd <= fd)
		head = head->next;
	if (head->fd == fd)
		return (read_line(head));
	_fd = malloc(sizeof(*_fd));
	if (_fd == NULL)
		return (NULL);
	if (fd < head->fd)
	{
		memcpy(_fd, head, sizeof(*head)), memset(head, 0, sizeof(*head));
		head->fd = fd, head->next = _fd;
		return (read_line(head));
	}
	memset(_fd, 0, sizeof(*_fd));
	_fd->fd = fd, _fd->next = head->next, head->next = _fd;
	return (read_line(_fd));
}
/**
 * read_line - fread the buffer
 * Description: update the state the race and printed
 * @buffer: the fd buffer to read
 * section header: the header of this function is _getline.h
 * Return: the readed line
 */
char *read_line(vuffer *buffer)
{
	char vuf[READ_SIZE + 1], *ptr, *line, *actual;
	ssize_t _read = 0, size;

	size = buffer->len - buffer->i, actual = buffer->vuf + buffer->i;
	ptr = find_char(actual, '\n', size);
	if (!buffer->len || buffer->i >= buffer->len || !ptr)
	{
		while (1)
		{
			_read = read(buffer->fd, vuf, READ_SIZE);
			if (_read < 0 || (_read == 0 && !buffer->len))
			{
				buffer->vuf ? free(buffer->vuf), buffer->vuf = NULL : NULL;
				return (buffer->vuf);
			}
			if (_read == 0)
			{	ptr = buffer->vuf + buffer->len;
				break;
			}
			buffer->vuf = _realloc(buffer->vuf, buffer->len, buffer->len + _read + 1);
			if (buffer->vuf == NULL)
				return (NULL);
			memcpy(buffer->vuf + buffer->len, vuf, _read), buffer->len += _read;
			actual = buffer->vuf + (buffer->len - _read);
			ptr = find_char(actual, '\n', _read);
			if (ptr != NULL)
			{	buffer->vuf[buffer->len] = 0;
				break;
			}
		}
	}
	*ptr = '\0', actual = buffer->vuf + buffer->i;
	line = malloc(1 + (ptr - (actual)));
	if (line == NULL)
		return (NULL);
	memcpy(line, buffer->vuf + buffer->i, 1 + (ptr - (actual)));
	buffer->i = (ptr - buffer->vuf) + 1;
	if (buffer->i >= buffer->len)
		buffer->i = buffer->len = 0, free(buffer->vuf), buffer->vuf = NULL;
	return (line);
}
/**
 * find_char - find a char and move the pointer to that
 * Description: update the state the race and printed
 * @s: the ptr
 * @c: char to find
 * @size: readed size
 * section header: the header of this function is _getline.h
 * Return: the ptr moved to the char
 */
char *find_char(char *s, char c, ssize_t size)
{
	if (s == NULL)
		return (NULL);
	do {
		if (*s == c)
			return (s);
		s++;
	} while (--size > 0);
	return (NULL);
}
/**
 * _realloc - reallocate memory
 * @ptr:the space in memory to realloc
 * @old_size: the previous size.
 * @new_size: the new size of the memory
 * Description: reallocate memory
 * section header: the header of this function is _getline.h
 * Return: no return.
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *p;

	if (new_size == old_size)
		return (ptr);
	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}
	if (ptr == NULL)
	{
		p = malloc(new_size);
		if (p == NULL)
		{
			free(ptr);
			return (NULL);
		}
		free(ptr);
		return (p);
	}
	p = malloc(new_size);
	if (p == NULL)
	{
		free(ptr);
		return (NULL);
	}
	if (new_size > old_size)
		memcpy(p, ptr, old_size);
	free(ptr);
	return (p);
}
/**
 * end_of_file - manage the end of reading
 * Description: free all and return
 * @head: the vuffer of the read
 * section header: the header of this function is _getline.h
 * Return: void
 */
void end_of_file(vuffer *head)
{
	vuffer *fb = NULL, *temp;

	if (head->vuf)
		free(head->vuf), head->vuf = NULL;
	for (fb = head->next; fb;)
	{
		if (fb->vuf)
		{
			free(fb->vuf);
			fb->vuf = NULL;
		}
		temp = fb;
		fb = fb->next;
		free(temp);
	}
	memset(&head, 0, sizeof(head));
}
