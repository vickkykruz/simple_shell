#include "shell.h"
/***/
void solo_sh(data_list *list_t)
{
	char *path;

	list_t->intact = 0;

	for (; ;)
	{
		path = is_shell(list_t);
		if (!path && list_t->builtin == 0)
			sh_exit(list_t);
		else if (!path && list_t->builtin == 1)
			continue;

		/* Make the struct elemnets builtin to default */
		list_t->builtin = 0;
		list_t->pid = fork();
		if (list_t->pid == 0) /* if failed */
		{
			list_t->status = execve(path, list_t->arry, list_t->env);
			/* if the process failed */
			if (list_t->status == -1)
			{
				write(STDERR_FILENO, list_t->arv[0], _strlen(list_t->arv[0]));
				write(STDERR_FILENO, ": ", 2);
				write(STDERR_FILENO, list_t->arry[0], _strlen(list_t->arry[0]));
				write(STDERR_FILENO, "Permission denied\n", 20);
				free(path);
				list_t->status = 13;
				sh_exit(list_t);
			}
		}
		else
		{
			wait(&list_t->status);
			list_t->status = WEXITSTATUS(list_t->status);
		}
		free_arr_ptr(list_t->arry);
		free(path);
	}
}
/**/
int arry_len(int num)
{
	int len = 1;
	unsigned int n;

	if (num < 0)
	{
		len++;
		n = num * -1;
	}
	else
		n = num;

	while (n > 9)
	{
		len++;
		n = n / 10;
	}
	return (len);
}
