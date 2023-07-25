#include "shell.h"
/**/
int cmd_cd_err(data_list *list_t, int num)
{
	/** Identicate the error value gotting from cmd_cd */
	if (num == 2)
	{
		write(STDERR_FILENO, list_t->arv[0], _strlen(list_t->arv[0]));
		write(STDERR_FILENO, ": Usage: setenv variable value\n", 31);
		return (1);
	}

	if (num == 3)
	{
		write(STDERR_FILENO, list_t->arv[0], _strlen(list_t->arv[0]));
		write(STDERR_FILENO, ": Usage: unsetenv variable value", 33);
		return (1);
	}

	if (num == 4)
	{
		write(STDOUT_FILENO, list_t->arry[1], _strlen(list_t->arry[1]));
		write(STDOUT_FILENO, ": Oldpwd is not set\n", 17);
		return (0);
	}

	if (num == 1)
	{
		write(STDERR_FILENO, list_t->arv[0], _strlen(list_t->arv[0]));
		write(STDERR_FILENO, ": ", 2);
		write(STDERR_FILENO, list_t->arry[0], 2);
		write(STDERR_FILENO, ": ", 2);
		write(STDERR_FILENO, list_t->arry[1], _strlen(list_t->arry[1]));
		write(STDERR_FILENO, "No such file or directory\n", 28);
		return (1);
	}
	return (1);
}
int _cd(data_list *list_t)
{
	int i, j = 0;
	char *npwd, *opwd = _getenv(list_t, "PWD");

	if (list_t->arry[1] == NULL)
	{
		free_arr_ptr(list_t->arry);
		list_t->arry = malloc(sizeof(char *) * 3);
		list_t->arry[0] = _strdup("cd");
		list_t->arry[1] = _getenv(list_t, "HOME");
		list_t->arry[2] = NULL;
	}
	else if (_strcmp(list_t->arry[1], "-") == 0)
	{
		free(list_t->arry[1]);
		list_t->arry[1] = _getenv(list_t, "OLDPWD");
		j++;
	}

	if (list_t->arry[1] == NULL)
		j = cmd_cd_err(list_t, 1);
	else
	{
		i = chdir(list_t->arry[1]);
		if (i == -1)
		{
			cmd_cd_err(list_t, 1);
			free(opwd);
			return (2);
		}
	}
	if (j == 1)
	{
		write(STDOUT_FILENO, list_t->arry[1], _strlen(list_t->arry[1]));
		write(STDOUT_FILENO, "\n", 1);
	}
	npwd = getcwd(NULL, BUFF_SIZE);
	modify_directory(list_t, "new", npwd);
	modify_directory(list_t, "old", opwd);
	free(npwd);
	free(opwd);

	return (0);
}
/****/
void modify_directory(data_list *list_t, char *dir_path, char *ndir)
{
	/* Free the the array sting if any **/
	free_arr_ptr(list_t->arry);
	list_t->arry = malloc(sizeof(char *) * 4);
	list_t->arry[0] = _strdup("setenv");

	if (_strcmp(dir_path, "old") == 0)
		list_t->arry[1] = _strdup("OLDPWD");
	else if (_strcmp(dir_path, "new") == 0)
		list_t->arry[1] = _strdup("PWD");

	list_t->arry[2] = _strdup(ndir);
	list_t->arry[3] = NULL;

	_set(list_t);
}
