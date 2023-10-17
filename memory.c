#include "shell.h"

/**
 * bfree - Frees a pointer and sets it to NULL.
 * a function that frees a pointer
 * @ptr: Address of the pointer to free.
 *
 * Return: 1 if freed, otherwise 0.
 */
int bfree(void **ptr)
{
if (ptr && *ptr)
{
free(*ptr);
*ptr = NULL;
return (1);
}
return (0);
}
