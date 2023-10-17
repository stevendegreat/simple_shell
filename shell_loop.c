#include "shell.h"

/**
 * hsh - main shell loop
 * a function main shell loop
 * @av: the argument vector from main()
 * @info: the parameter & return info struct
 *
 * Return: 0 on success, 1 on error, or error code
 */
int hsh(info_t *info, char **av)
{
ssize_t r = 0;
int builtin_ret = 0;

while (r != -1 && builtin_ret != -2)
{
clear_info(info);
if (interactive(info))
 _puts("$ ");
_eputchar(BUF_FLUSH);
r = get_input(info);
if (r != -1)
{
set_info(info, av);
builtin_ret = find_builtin(info);
if (builtin_ret == -1)
find_cmd(info);
}
else if (interactive(info))
_putchar('\n');
free_info(info, 0);
}
write_history(info);
free_info(info, 1);
if (!interactive(info) && info->status)
exit(info->status);
if (builtin_ret == -2)
{
if (info->err_num == -1)
exit(info->status);
exit(info->err_num);
}
return (builtin_ret);
}


/**
 * find_builtin - finds a builtin command
 * @info: the parameter & return info struct
 *
 * Return: -1 if builtin not found,
 *0 if builtin executed successfully,
 *1 if builtin found but not successful,
 *-2 if builtin signals exit()
 */
int find_builtin(info_t *info)
{
int i, built_in_ret = -1;

/*Define a table of built-in commands and their corresponding functions*/
builtin_table builtintbl[] = {
{"exit", _myexit},
{"env", _myenv},
{"help", _myhelp},
{"history", _myhistory},
{"setenv", _mysetenv},
{"unsetenv", _myunsetenv},
{"cd", _mycd},
{"alias", _myalias},
{NULL, NULL}
};

/*Loop through the built-in table to find the command*/
for (i = 0; builtintbl[i].type; i++)
{
if (_strcmp(info->argv[0], builtintbl[i].type) == 0)
{
info->line_count++;
/*Check if the function pointer is valid*/
if (builtintbl[i].func != NULL)
{
built_in_ret = builtintbl[i].func(info);
}
else
{
/* Handle the case where the function pointer is NULL*/
fprintf(stderr, "Internal error: %s function is not defined.\n",
(info->argv[0]));
built_in_ret = 1; /*Indicate an error*/
}
break;
}
}
return (built_in_ret);
}

/**
 * find_cmd - finds a command in PATH
 * @info: the parameter & return info struct
 *
 * Return: void
 */
void find_cmd(info_t *info)
{
char *path = NULL;
int i, k;

info->path = info->argv[0];
if (info->linecount_flag == 1)
{
info->line_count++;
info->linecount_flag = 0;
}
for (i = 0, k = 0; info->arg[i]; i++)
if (!is_delim(info->arg[i], " \t\n"))
k++;
if (!k)
return;

path = find_path(info, _getenv(info, "PATH="), info->argv[0]);
if (path)
{
info->path = path;
fork_cmd(info);
}
else
{
if ((interactive(info) || _getenv(info, "PATH=")) && info->argv[0][0] == '/' && is_cmd(info, info->argv[0]))
fork_cmd(info);
else if (*(info->arg) != '\n')
{
info->status = 127;
print_error(info, "not found\n");
		}
}
}

/**
 * fork_cmd - forks a an exec thread to run cmd
 * a function that forks a an exec thread
 * @info: the parameter & return info struct
 *
 * Return: void
 */
void fork_cmd(info_t *info)
{
pid_t child_pid;

child_pid = fork();
if (child_pid == -1)
{
/* TODO: PUT ERROR FUNCTION */
perror("Error:");
return;
}
if (child_pid == 0)
{
if (execve(info->path, info->argv, get_environ(info)) == -1)
{
free_info(info, 1);
if (errno == EACCES)
exit(126);
exit(1);
}
/* TODO: PUT ERROR FUNCTION */
}
else
{
wait(&(info->status));
if (WIFEXITED(info->status))
{
info->status = WEXITSTATUS(info->status);
if (info->status == 126)
print_error(info, "Permission denied\n");
}
}
}
