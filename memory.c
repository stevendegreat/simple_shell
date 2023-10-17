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
if (ptr == NULL || *ptr == NULL)

return (0); /*Nothing to free*/
}
free(*ptr);
*ptr = NULL;
return (1);
}
}
