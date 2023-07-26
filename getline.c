#include "shell.h"
/**
 * _getline - This is a function that return the inpu line stream /file
 * description
 * @buff: This is an argument that holds the adressbof the buffer
 * @num: This is an argument that pointes to the size of the buffer
 * @stream: This is an argument that hold the input read stream
 *
 * Return: This function return the number of charcters
 */
ssize_t _getline(char **buff, size_t *num, FILE *stream)
{
	char *buff_size, ch = 'c';
	size_t size;
	int fd;
	static ssize_t line;
	ssize_t n;

	/** Allocate space to store the command line **/
	buff_size = malloc(sizeof(char) * BUFF_SIZE);
	if (!buff_size)
		return (-1);
	fd = fileno(stream);

	while (ch != NEW_LINE)
	{
		n = read(fd, &ch, 1);
		if ((n == 0 && line == 0) || n == -1)
		{
			free(buff_size);
			return (-1);
		}
		if (n == 0 && line != 0)
		{
			line++;
			break;
		}
		if (line >= BUFF_SIZE)
			buff_size = _realloc(buff_size, line, line + 1);

		buff_size[line] = ch;
		line++;
	}
	buff_size[line] = '\0';
	insert_line(buff, num, buff_size, line);
	size = line;
	if (n != 0)
		line = 0;
	return (size);
}
/**
 * get_cmd - This is a function that return the the command gotten from the
 * standard input
 * @list_t: This is an argument that reprsent the datat_list struct that
 * store the argument value
 * @buff: This is an argument that resprsent the buffer memory that holds the
 * address
 * @num: This is an argument that reprsent hold the size of the memory passed
 *
 * Return: This is a function that return the spilited token of the command
 */
char **get_cmd(data_list *list_t, char *buff, size_t num)
{
	ssize_t i = 0, n;
	size_t j = 0;
	char *token;
	char **idx_arr = NULL;

	/** Get the input command **/
	n = _getline(&buff, &num, stdin);
	if (n == -1)/* if the function failed */
	{
		free(buff);
		list_t->intact = 3;
		return (idx_arr);
	}
	/* Remove comment and return the number of idexs */
	n = remove_comments(&buff);
	if (n == 0) /* if failed */
		return (NULL);

	for (i = 0; i < n; i++)
	{
		if (buff[i] == ' ' || buff[i] == '\n' || buff[i] == '\t' ||
buff[i] == '\r' || buff[i] == '\a')
			j++;
		else
			continue;
	}
	idx_arr = malloc(sizeof(char *) * (j + 1));
	token = _strtoken(buff, DELIME_LIST);
	i = 0;

	while (token != NULL)
	{
		idx_arr[i] = malloc(sizeof(char) * (_strlen(token) + 1));
		_strcpy(idx_arr[i], token);
		token = _strtoken(NULL, DELIME_LIST);
		i++;
	}
	idx_arr[i] = NULL;
	free(buff);
	return (idx_arr);
}
/**
 * _set - This is a function that return the modified environment variables
 * @list_t: This is an argument that represent the data_list struct
 *
 * Return: This function return (0) as sucess otherwise (12) as error
 */
int _set(data_list *list_t)
{
	char **nevn;
	int i, j, k = 0, num, chk = 0;

	for (i = 0; list_t->env[i]; i++)
		;
	/* check if the fiest index or second index is NULL */
	if (list_t->arry[1] == NULL || list_t->arry[2] == NULL)
		return (cmd_cd_err(list_t, 2));
	nevn = malloc(sizeof(char *) * (i + 2));
	if (!nevn)
		return (12);

	for (i = 0; list_t->env[i]; i++)
	{
		j = 0, num = 0;
		while (list_t->env[i][j] != '=' && list_t->arry[1][j] != '\0')
		{
			if (list_t->env[i][j] != list_t->arry[1][j])
				num = 1;
			j++;
		}
		if (num == 0)
		{
			nevn[k] = modify_env(list_t);
			k++, chk = 1;
			continue;
		}
		nevn[k] = _strdup(list_t->env[i]);
		k++;
	}
	if (chk == 0)
	{
		nevn[k] = modify_env(list_t);
		nevn[k + 1] = NULL;
	}
	else
		nevn[k] = NULL;
	free_arr_ptr(list_t->env);
	list_t->env = nevn;
	return (0);
}
/**
 * _unset - This is a function that return the removed environment variable
 * @list_t: This is an argument that reprsent the data_list struct
 *
 * Return: This function return the sucvess status (0) otherwise (-1) as error
 */
int _unset(data_list *list_t)
{
	char **nevn;
	int i, j, k = 0, num, chk = 0;

	/** Get the total len of the env **/
	for (i = 0; list_t->env[i]; i++)
		;
	if (list_t->arry[1] == NULL)
		return (cmd_cd_err(list_t, 3));
	/* Allocate spave for the env */
	nevn = malloc(sizeof(char *) * (i + 1));
	if (!nevn)
		return (12);
	/* Run the loop */
	for (i = 0; list_t->env[i]; i++)
	{
		j = 0, num = 0;
		while (list_t->env[i][j] != '=' && list_t->arry[1][j] != '\0')
		{
			if (list_t->env[i][j] != list_t->arry[1][j])
				num = 1;
			j++;
		}
		if (num == 0)
		{
			chk = 1;
			continue;
		}
		nevn[k] = _strdup(list_t->env[i]);
		k++;
	}
	nevn[k] = NULL;
	if (chk == 0)
	{
		perror("Environment variable does not exist\n");
		free_arr_ptr(nevn);
		return (6);
	}
	free_arr_ptr(list_t->env);
	list_t->env = nevn;
	return (0);
}
