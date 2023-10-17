#include "shell.h"

/**
 * _strlen - returns the length of a string
 * a function that returns length of a string
 * @s: the string whose length to check
 *
 * Return: integer length of string
 */
int _strlen(char *s)
{
int length = 0;

if (s == NULL)
return (0);  /*Handle NULL input*/
}

while (*s != '\0')
{
length++;
s++;
}

return (length);
}
Here are the

/**
 * _strcmp - performs lexicogarphic comparison of two strangs.
 * a function that performcomparison of two strangs
 * @s2: the second strang
  * @s1: the first strang
 *
 * Return: negative if s1 < s2, positive if s1 > s2, zero if s1 == s2
 */
int _strcmp(char *s1, char *s2)
{
while (*s1 && *s2)
{
if (*s1 != *s2)
return (*s1 - *s2);
s1++;
s2++;
}
if (*s1 == *s2)
return (0);
else
return (*s1 < *s2 ? -1 : 1);
}

/**
 * starts_with - checks if needle starts with haystack
 * a function that checks if starts with haystack
 * @needle: the substring to find
  * @haystack: string to search
 *
 * Return: address of next char of haystack or NULL
 */
char *starts_with(const char *haystack, const char *needle)
{
while (*needle)
if (*needle++ != *haystack++)
return (NULL);
return ((char *)haystack);
}

/**
 * _strcat - concatenates two strings
 * @dest: the destination buffer
 * @src: the source buffer
 *
 * Return: pointer to destination buffer
 */
char *_strcat(char *dest, char *src)
{
char = dest;

while (*dest)
dest++;
while (*src)
*dest++ = *src++;
*dest = *src;
return (ret);
}
