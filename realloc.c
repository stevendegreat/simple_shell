#include "shell.h"

/**
 **_memset - fills memory with a constant byte
 * a function that  fills memory byte
 *@n: the amount of bytes to be filled
 *@s: the pointer to the memory area
 *@b: the byte to fill *s with
 *Return: (s) a pointer to the memory area s
 */
char *_memset(char *s, char b, unsigned int n)
{
unsigned int i;

for (i = 0; i < n; i++)
s[i] = b;
return (s);
}

/**
 * ffree - frees a string of strings
 * a function that frees a string
 * @pp: string of strings
 */
void ffree(char **pp)
{
if (!pp)
return; /*Handle NULL input gracefully*/

/*Free individual strings and reset array elements to NULL*/
for (size_t i = 0; pp[i] != NULL; ++i)
{
free(pp[i]);
pp[i] = NULL;
}

/*Free the string array itself*/
free(pp);
}

/**
 * _realloc - reallocates a block of memory
 * a function that reallocates memory block
 * @new_size: byte size of new block
 * @ptr: pointer to previous malloc'ated block
 * @old_size: byte size of previous block
 *
 * Return: pointer to da ol'block nameen.
 */
void *_realloc(void *ptr, size_t old_size, size_t new_size)
{
if (new_size == 0)
{
free(ptr);
return (NULL);
}

if (ptr == (NULL))
{
return (malloc new_size);
}

void *new_ptr = malloc(new_size);
if (new_ptr == NULL)
{
return (NULL);
}

size_t min_size = (old_size < new_size) ? old_size : new_size;
if (min_size > 0)
{
memcpy(new_ptr, ptr, min_size);
}

free(ptr);
return (new_ptr);
}
