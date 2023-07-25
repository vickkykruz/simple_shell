#include "shell.h"
/****/
void expand_variable(data_list *list_t)
{
	char *str, *val;
	int i = 0, j, k;

	while (list_t->arry[i])
	{
		if (_strcmp(list_t->arry[i], "$$") == 0)
		{
			free(list_t->arry[i]);
			str = _itoa(list_t->pid);
			list_t->arry[i] = _strdup(str);
			free(str);
		}
		else if (_strcmp(list_t->arry[i], "$?") == 0)
		{
			free(list_t->arry[i]);
			str = _itoa(list_t->status);
			list_t->arry[i] = _strdup(str);
			free(str);
		}
		else if (list_t->arry[i][0] == '$')
		{
			str = malloc(sizeof(char) * _strlen(list_t->arry[i]));
			for (j = 1, k = 0; list_t->arry[i][j]; j++, k++)
				str[k] = list_t->arry[i][j];
			str[k] = '\0';
			val = _getenv(list_t, str);
			if (val == NULL)
			{
				free(val);
				free(str);
			}
			else
			{
				free(list_t->arry[i]);
				free(str);
				list_t->arry[i] = _strdup(val);
				free(val);
			}
		}
		i++;
	}
}
