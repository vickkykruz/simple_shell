#include "shell.h"
/**
 * get_cmd_fun - This is a function that return the builtins functions
 * @args: This is an argument that reprsent the spilited command arguments
 *
 * Return: This function return the buitin function otherwise Null
 */
int (*get_cmd_fun(char **args))(data_list *)
{
	builtin_fun cmd_builtin[] = BUITIN_FUNC;

	int i = 0;

	if (args != NULL)
	{
		while (cmd_builtin[i].fun != NULL)
		{
			if (_strcmp(cmd_builtin[i].cmd, args[0]) == 0)
				return (cmd_builtin[i].fun);
			i++;
		}
	}

	return (NULL);
}
