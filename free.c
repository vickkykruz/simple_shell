#include "shell.h"
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
/***/
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
/***/
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
