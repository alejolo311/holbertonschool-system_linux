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
	size_t i;

	for (i = 0; i < strlen(valid); i++)
	{
		if (valid[i] == arg)
			return (true);
	}
	return (false);
}
