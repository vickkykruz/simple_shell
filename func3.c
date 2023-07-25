#include "shell.h"
/**
 * _realloc - This is a function that return the reallocated memory
 * @ptr: Thisnis an argument thay reprsent the previous allocated memory
 * @o_size: This is an argument that reprsent the prevoius pointer size
 * @n_size: This is an argument that reprsent the new size pointer
 *
 * Return: This function return a pointer to the new allocated memory
 */
void *_realloc(void *ptr, unsigned int o_size, unsigned int n_size)
{
	/*** initizaled the variables **/
	char *new_node;
	unsigned int i;

	if (ptr == NULL)
	{
		ptr = malloc(n_size);
		return (ptr);
	}

	if (o_size == n_size)
		return (ptr);

	if (n_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}

	/** Allocate the new size */
	new_node = malloc(n_size);
	if (new_node == NULL)
		return (NULL);

	/** Increament the size **/
	for (i = 0; i < n_size && i < o_size; i++)
		;
	memcpy(new_node, ptr, i);
	free(ptr);

	return (new_node);
}
/**
 * _memcpy - This is a functiom that return the copied data to another pointer
 * @des: This is an argument that reprsent the destination pointer
 * @src: This is an argument that reprsent the soruce pointet
 * @size: This is an argumemt that reprsent the size of the data
 *
 * Return: This function returm the copied data as void
 */
void _memcpy(void *des, const void *src, unsigned int size)
{
	char *ptr = (char *)src;
	char *new_node = (char *)des;
	unsigned int i;

	for (i = 0; i < size; i++)
		new_node[i] = ptr[i];
}
/**
 * insert_line - This is a function that return the inserted buffer onto the
 * linteprt
 * @lineptr: This is an argument that reprsent the address passed into getline
 * @num: This is an argument that reprsent the size of the line
 * @buff: This is an argument that reprsent the read in cell
 * @size: Thisnis an argument thay reprsent the size of the buffer
 *
 * Return: This function return a NULL
 */
void insert_line(char **lineptr, size_t *num, char *buff, size_t size)
{
	if (*lineptr == NULL || *num < size)
	{
		if (size > BUFF_SIZE)
			*num = size;
		else
			*num = BUFF_SIZE;
		*lineptr = buff;
	}
	else
	{
		_strcpy(*lineptr, buff);
		free(buff);
	}
}
/**
 * reverse_str -  This is a function that return thereversed strimg
 * @str: This is an argument that reprsent the string to be reseved
 *
 * Return: This function return the destinated pointer
 */
void reverse_str(char *str)
{
	int i, j, k;
	char tmp;

	for (i = 0; str[i] != '\0'; i++)
		;

	for (j = 0; j < (i - 1); j++)
	{
		for (k = j + 1; k > 0; k--)
		{
			tmp = str[k];
			str[k] = str[k - 1];
			str[k - 1] = tmp;
		}
	}
}
