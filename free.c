#include "shell.h"
/**
 * free_alias - This is a function that free the alias linked list
 * @lists: This is an argument that reprsent the alias list struct
 *
 * Return: This function return void (nothing)
 */
void free_alias(alias_list *lists)
{
	alias_list *tmp = lists, *prv;

	if (lists)
	{
		while (tmp->next)
		{
			prv = tmp;
			tmp = tmp->next;
			free(prv->str);
			free(prv->val);
			free(prv);
		}

		free(tmp->str);
		free(tmp->val);
		free(tmp);
	}
}
/**
 * free_arr_ptr - This is a function that free the array pointers
 * @ptr: This is an argument that reprsent the given pointer passed
 *
 * Return: This function return a void (nothing)
 */
void free_arr_ptr(char **ptr)
{
	int i;

	if (ptr != NULL)
	{
		for (i = 0; ptr[i]; i++)
			free(ptr[i]);
		free(ptr);
	}
}
/**
 * free_list - This is a function that free the path linked list
 * @list: This is an argument that represent the path list struct
 *
 * Return: This function return the free path linked list
 */
void free_list(path_list *list)
{
	path_list *tmp = list, *prv;

	if (list)
	{
		while (tmp->next)
		{
			prv = tmp;
			tmp = tmp->next;
			free(prv->str_path);
			free(prv);
		}

		free(tmp->str_path);
		free(tmp);
	}
}
