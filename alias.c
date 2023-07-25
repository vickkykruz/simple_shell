#include "shell.h"
/***/
alias_list *add_alias(alias_list **list, char *str, char *val)
{
	alias_list *tmp = *list, *node;
	char *s;

	if (val[0] == 39)
		s = _strdup(val);
	else
	{
		s = malloc(sizeof(char) *  (_strlen(val) + 3));
		_strcpy(s, "'");
		_strcat(s, val);
		_strcat(s, "'");
	}

	while (tmp)
	{
		if (_strcmp(tmp->str, str) == 0)
		{
			free(tmp->val);
			tmp->val = _strdup(s);
			free(s);
			return (tmp);
		}
		tmp = tmp->next;
	}
	tmp = *list;
	node = malloc(sizeof(alias_list));
	if (node == NULL)
		return (NULL);
	node->str = _strdup(str);
	node->val = _strdup(s);
	node->next = NULL;

	if (tmp == NULL)
		*list = node;
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = node;
	}
	free(s);
	return (*list);
}
/**/
int set_alias(data_list *list_t, char *ar)
{
	char *str, *val, *na;

	str = _strdup(ar);
	na = _strtoken(str, "=");
	val = _strtoken(NULL, "");

	add_alias(&list_t->list_alias, na, val);
	if (list_t->list_alias == NULL)
	{
		write(STDERR_FILENO, list_t->arv[0], _strlen(list_t->arv[0]));
		write(STDERR_FILENO, ": unable to add alias\n", 22);
		free(str);
		return (12);
	}

	free(str);
	return (0);
}
/**/
int _alias(data_list *list_t)
{
	int i, j, chk, res = 0;

	if (list_t->arry[1] == NULL)
		res = print_alias_list(list_t);
	else
	{
		for (i = 1; list_t->arry[i]; i++)
		{
			chk = 0;
			for (j = 0; list_t->arry[i][j]; j++)
			{
				if (list_t->arry[i][j] == '=')
				{
					chk = 1;
					res = set_alias(list_t, list_t->arry[i]);
					break;
				}
			}

			if (chk == 0)
				res = print_alias(list_t, list_t->arry[i]);
		}
	}
	return (res);
}
/***/
void validate_alias(data_list *list_t)
{
	char *cmd;
	alias_list *tmp;
	int i, j, len;

	tmp = list_t->list_alias;
	while (tmp)
	{
		if (_strcmp(tmp->str, list_t->arry[0]) == 0)
		{
			len = _strlen(tmp->val);
			cmd = malloc(sizeof(char) * (len - 1));

			for (i = 1, j = 0; i < len - 1; i++, j++)
				cmd[j] = tmp->val[i];
			cmd[j] = '\0';

			free(list_t->arry[0]);
			list_t->arry[0] = cmd;
			break;
		}
		tmp = tmp->next;
	}
}
