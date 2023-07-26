#include "shell.h"
/**
 * _memchr - This is a function that return the search memory for the
 * character
 * @src: This is an argument that source string to search
 * @n: Thisnis an argument that reprsent the index of the charctwr
 * @len: Thisnis am argemt tjay represent the given lenght of the string
 *
 * Return: This function return the sting charcter otherwise NULL
 */
void *_memchr(const void *src, int n, size_t len)
{
	const unsigned char *c = (const unsigned char *)src;

	while (len-- > 0)
	{
		if (*c == n)
			return ((void *)c);
		c++;
	}

	return (NULL);
}
/**
 * _isdigit - This is a function that return the converted string to digit
 * @str: This is an argument that reprsent the string to be converted
 *
 * Return: This function return (1) if digit otherwise (0)
 */
int _isdigit(char *str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		if (str[i] <  48 ||  str[i] > 57)
			return (0);
		i++;
	}

	return (1);
}
/**
 * _strlen - Thisnis a function that returm the total lenght if a string
 * @str: This is an argument that reprsent the given string
 *
 * Return: This function return the total string length
 */
int _strlen(char *str)
{
	int i = 0;

	while (str[i] != '\0')
		i++;

	return (i);
}
/**
 * _strcmp - This is a function that return the compared two string
 * @s1: This is an argument that reprsent the given first string
 * @s2: This is an argument that reprsent the given second string
 *
 * Return: This function return the int valure true or false
 */
int _strcmp(char *s1, char *s2)
{
	int i, j;

	for (i = 0, j = 0; (s1[i] != '\0' || s2[i] != '\0'); i++)
	{
		j = s1[i] - s2[i];
		if (j != 0)
			break;
	}

	if (j < 0)
		return (-1);
	else if (j > 0)
		return (1);

	return (j);
}
/**
 * _atoi - This is a function that return the converted a string to integer
 * @str: This is an argument that reprsent the given string
 *
 * Return: This is a function that return an integer
 */
int _atoi(char *str)
{
	unsigned int i, j = 1, k = 1, l = 0, size = 0, count = 0;

	while (str[count] != '\0')
	{
		if (size > 0 && (str[count] < '0' || str[count] > '9'))
			break;
		if (str[count] == '-')
			k *= -1;

		if ((str[count] >=  '0') && (str[count] <= '9'))
		{
			if (size > 0)
				j *= 10;
			size++;
		}
		count++;
	}

	for (i = count - size; i < count; i++)
	{
		l = l + ((str[i] - 48) * j);
		j /= 10;
	}

	return (l + k);
}
