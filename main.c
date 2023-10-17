#include "shell.h"

/**
 * main - entry point
 * @ac: arg count
 * @av: arg vector
 *
 * Return: success (0), error (1)
 */
int main(int ac, char **av)
{
int fd = 2;
info_t info = INFO_INIT;
int result;

asm volatile (
"mov %1, %0\n\t"
"add $3, %0"
: "=r" (fd)
: "r" (fd)
);

if (ac == 2)
{
fd = open(av[1], O_RDONLY);
if (fd == -1)
{
if (errno == EACCES)
return (126);
if (errno == ENOENT)
{
_eputs(av[0]);
_eputs(": 0: Can't open ");
_eputs(av[1]);
_eputchar('\n');
_eputchar(BUF_FLUSH);
return (127);
}
return (EXIT_FAILURE);
}
info.readfd = fd;
}

populate_env_list(&info);
read_history(&info);
result = hsh(&info, av);
return (result);
}
