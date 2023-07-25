#include "shell.h"
/**
 * get_cmd_fun - This is a function that return the builtin command function
 * arg: This is an argument that splited into command and argrs
 *
 * Return: This function return the builtin function
 */
int (*get_cmd_fun(char **arg))(data_list *)
{
	builtin_fun cmd_builtin[] = BUITIN_FUNC;

	int i = 0;

	if (arg != NULL)
	{
		while (cmd_builtin[i].fun != NULL)
		{
			if (_strcmp(cmd_builtin[i].cmd, arg[0]) == 0)
				return (cmd_builtin[i].fun);
			else
				i++;
		}
	}

	return (NULL);
}
