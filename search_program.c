#include "shell.h"
/**
 * find_path - This is a function that return the searchwd path to the linked
 * list
 * @lists: This is an argument that reprsent the pointer to path list
 * @f: This is an argument that reprsent file to search for
 *
 * Return: This function return the searched file as a pointer
 */
char *find_path(path_list *lists, char *f)
{
	struct stat s;
	path_list *tmp = lists;
	char *dir;

	/** Loop the system stuct to find a match **/
	while (tmp)
	{
		dir = malloc(sizeof(char) * (_strlen(tmp->str_path) + _strlen(f) + 2));
		if (f[0] == '/')
		{
			free(dir);
			if (stat(f, &s) == 0)
			{
				dir = _strdup(f);
				return (dir);
			}
			else
				return (NULL);
		}

		_strcpy(dir, tmp->str_path);
		_strcat(dir, "/");
		_strcat(dir, f);
		if (stat(dir, &s) == 0)
			return (dir);

		free(dir);
		tmp = tmp->next;
	}
	return (NULL);
}
/**
 * add_node_end - This is a function that return the added node to end of the
 * path_list
 * @head: This is an argument that reprsent the poinyer of the list
 * @str: This is an argument that reprsent the string to be added
 *
 * Return: This function return the address ofnthe list
 */
path_list *add_node_end(path_list **head, char *str)
{
	path_list *new_node, *tmp;

	tmp = *head;
	new_node = malloc(sizeof(path_list));
	if (!new_node)
		return (NULL);

	new_node->str_path = _strdup(str);
	new_node->next = NULL;

	if (!tmp)
		*head = new_node;
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new_node;
	}

	return (*head);
}
/**
 * path_to_list - Thisnis an argumemt that reprsent the created linked list
 * to each directory that contain PATH
 * @list_t: This is an argument that reprsent the data_list struct
 *
 * Return: This function return the coverted PATH
 */
path_list *path_to_list(data_list *list_t)
{
	int i, j, k, chk;
	char *str;
	path_list *list = NULL;
	char arr[5] = "PATH";

	for (i = 0; list_t->env[i]; i++)
	{
		j = 0, chk = 0;
		while (list_t->env[i][j] != '=' && arr[j] != '\0')
		{
			if (list_t->env[i][j] != arr[j])
				chk = 1;
			j++;
		} k = 0;
		if (chk == 0)
		{
			j++;
			while (list_t->env[i][j])
			{
				if (list_t->env[i][j] == ':')
				{
					str[k] = '\0', k = 0;
					add_node_end(&list, str);
					free(str);
				}
				else
				{
					if (k == 0)
						str = malloc(sizeof(char) * 150);
					str[k] = list_t->env[i][j], k++;
				} j++;
			} str[k] = '\0';
			add_node_end(&list, str);
			free(str);
			break;
		}
	} str = _getenv(list_t, "PWD");
	add_node_end(&list, str);
	free(str);
	return (list);
}
