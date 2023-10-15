#include "shell.h"

/**
 * interactive - returns true if shell is interactive mode
 * a function that returns true if interactive mode
 * @info: struct address
 *
 * Return: 0 otherwise, 1 if interactive mode
 */
int interactive(info_t *info)
{
return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * is_delim - checks a delimeter character
 * a function that check a delimeter character
 * @c: check char
 * @delim: the delimeter string
 * Return: 0 if false, 1 if true
 */
int is_delim(char c, char *delim)
{
while (*delim)
if (*delim++ == c)
return (1);
return (0);
}

/**
 *_isalpha - checks for alphabetic
 * a function that check for alphabet
 *@c: The input character
 *Return: 0 otherwise, 1 if c is alphabetic
 */

int _isalpha(int c)
{
if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
return (1);
else
return (0);
}

/**
 *_atoi - converts string to a integer
* a function that convert string to integer
 *@s: the converted string
 *Return: 0 if no numbers in string, converted number otherwise
 */

int _atoi(char *s)
{
int i, sign = 1, flag = 0, output;
unsigned int result = 0;

for (i = 0;  s[i] != '\0' && flag != 2; i++)
{
if (s[i] == '-')
sign *= -1;

if (s[i] >= '0' && s[i] <= '9')
{
flag = 1;
result *= 10;
result += (s[i] - '0');
}
else if (flag == 1)
flag = 2;
}

if (sign == -1)
output = -result;
else
output = result;

return (output);
}
