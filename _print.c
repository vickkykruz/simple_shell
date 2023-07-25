#include "shell.h"
/**
 * print_alias - This is a function that display the alias
 * @list_t: This is an argument that represent the data_list struct
 * 
 * Return: This function return an int (0) as sucess and (1) fauilure
*/
integer print_alias_list(data_list *list_t)
{
	alias_list *tmp;
	int len1, len2;
	char *ptr;

	tmp = list_t->list_alias;

	if (tmp == NULL)
		return (0);

	while (tmp)
	{
		len1 = _strlen(tmp->str);
		len2 = _strlen(tmp->val);
		ptr = malloc(sizeof(char) * (len1 + len2 + 2));
		if (ptr == NULL)
			return (12);

		_strcpy(ptr, tmp->str);
		_strcat(ptr, "=");
		_strcat(ptr, tmp->val);

		write(STDOUT_FILENO, ptr, len1 + len2 + 1);
		write(STDOUT_FILENO, "\n", 1);

		free(ptr);
		tmp = tmp->next;
	}
	return (0);
}
/***
 */
int print_alias(data_list *list_t, char *str)
{
	alias_list *tmp;
	int len1, len2;
	char *ptr = NULL;

	tmp = list_t->list_alias;
	if (tmp == NULL)
	{
		write(STDERR_FILENO, list_t->arv[0], _strlen(list_t->arv[0]));
		write(STDERR_FILENO, ": ", 2);
		write(STDERR_FILENO, "not found\n", 11);
		return (1);
	}
	while (tmp)
	{
		if (_strcmp(str, tmp->str) == 0)
		{
			len1 = _strlen(tmp->str);
			len2 = _strlen(tmp->val);
			ptr = malloc(sizeof(char) * (len1 + len2 + 2));
			if (ptr == NULL)
				return (12);
			_strcpy(ptr, tmp->str);
			_strcat(ptr, "=");
			_strcat(ptr, tmp->val);

			write(STDOUT_FILENO, ptr, len1 + len2 + 1);
			write(STDOUT_FILENO, "\n", 1);
			free(ptr);
		}
		tmp = tmp->next;
	}
	return (0);
}

