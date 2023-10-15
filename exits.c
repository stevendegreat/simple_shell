#include "shell.h"

/**
 *_strncpy - copies a string
 * a function that copies string
 *@src: the source string
 *@dest: the destination string to be copied to
 *@n: the amount of characters to be copied
 *Return: the concatenated string
 */
char *_strncpy(char *dest, char *src, int n)
{
char *s = dest;
int i, j;

i = 0;
while (src[i] != '\0' && i < n - 1)
{
dest[i] = src[i];
i++;
}
if (i < n)
{
j = i;
while (j < n)
{
dest[j] = '\0';
j++;
}
}
return (s);
}

/**
 *_strncat - concatenates two strings
 * a function that concatenates two strings
 *@src: the second string
 *@dest: the first string
 *@n: the amount of bytes to be maximally used
 *Return: the concatenated string
 */
char *_strncat(char *dest, char *src, int n)
{
char *s = dest;
int i, j;

j = 0;
i = 0;

while (dest[i] != '\0')
i++;
while (src[j] != '\0' && j < n)
{
dest[i] = src[j];
i++;
j++;
}
if (j < n)
dest[i] = '\0';
return (s);
}

/**
 *_strchr - locates a character in a string
 * a function locate char string
 *@c: the character to look for
 * @s: the string to be parsed
 *Return: (s) a pointer to the memory area s
 */
char *_strchr(char *s, char c)
{
do {
if (*s == c)
	return (s);
} while (*s++ != '\0');

return (NULL);
}
