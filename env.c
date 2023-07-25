#include "shell.h"
/**
 * _getenv - This is a function that return the value of the environment
 * variable
 * @list_t: This is an argument that represent the data_list struct
 * @str: This is an argument that reprsent the given string passed
 *
 * Return: This function return the pointer of the env value
 */
char *_getenv(data_list *list_t, char *str)
{
	char *val;
	int i, j, k, n, chk;

	for (i = 0; list_t->env[i]; i++)
	{
		j = 0, chk = 0;
		while (list_t->env[i][j] != '=' && str[j] != '\0')
		{
			if (list_t->env[i][j] != str[j])
				chk = 1;
			j++;
		}
		if (chk == 0 && list_t->env[i][j] == '=')
		{
			for (k = j + 1, n = 0; list_t->env[i][k]; k++, n++)
				;
			val = malloc(sizeof(char) * (n + 1));

			for (k = j + 1, n = 0; list_t->env[i][k]; n++, k++)
				val[n] = list_t->env[i][k];
			val[n] = '\0';

			return (val);
		}
	}

	return (NULL);
}
/**
 * _env - This is a function that return the printed environment varibale
 * @list_t: This is an argument that reprsent the data list struct
 *
 * Return: This function return the (0) as success
 */
int _env(data_list *list_t)
{
	int i = 0, len;

	while (list_t->env[i])
	{
		/* Get the len of each string passed by index */
		len = _strlen(list_t->env[i]);
		write(STDOUT_FILENO, list_t->env[i], len);
		write(STDOUT_FILENO, "\n", 1);
	}

	return (0);
}
/**
 * modify_env - This is a function that return modifid environment variable
 * @list_t: This is an argument that reprsent the data list struct
 *
 * Return: This function return the modified variable with value
 */
char *modify_env(data_list *list_t)
{
	int len1, len2, len;
	char *s;

	/** Get the lenght **/
	len1 = _strlen(list_t->arry[1]);
	len2 = _strlen(list_t->arry[2]);

	len = len1 + len2 + 2;
	/** Allocate space for the cmd **/
	s = malloc(sizeof(char) * len);
	if (!s)
		return (NULL);

	_strcpy(s, list_t->arry[1]);
	_strcat(s, "=");
	_strcat(s, list_t->arry[2]);

	return (s);
}
