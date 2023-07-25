#include "shell.h"
/**
 * remove_comments - This is a function that return the removed strip from
 * comment
 * @str: Thisnis an argument that reprsent the string buffer from _getline
 *
 * Return: This function return the status (0) otherwise the lenght if the
 * string buff
 */
int remove_comments(char **str)
{
	char *tmp = NULL, ptr = 'c';
	char *buff = _strdup(*str);
	int i, j = 0, n = 0;

	/* We want to free eqch index char in the buffer **/
	for (; buff[n] != '\0'; n++)
	{
		if (n == 0 && buff[n] == '#')
		{
			free(buff);
			return (0);
		}
		if (j == 0 && buff[n] == '#')
		{
			free(buff);
			return (0);
		}
		if (buff[n] == ' ' && buff[n] != '\t')
			j++;

		if (ptr == ' ' && buff[n] == '#')
			break;
		ptr = buff[n];
	}

	if (n == _strlen(*str))
	{
		free(buff);
		return (n);
	}
	tmp = malloc(sizeof(char) * (n + 2));
	for (i = 0; buff[i] != '#'; i++)
		tmp[i] = buff[i];
	tmp[i] = '\n';
	tmp[i + 1] = '\0';
	free(*str);

	*str = tmp;
	free(buff);

	return (n + 1);
}

