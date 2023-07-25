#include "shell.h"
/**
 * _strcat - This is a function that return the appended source to the
 * destination
 * @des: This is an argument that reprsent the exiting string
 * @src: Thie is an argument that reprsent the strieng to be appended to the
 * destination
 *
 * Return: This is a function that return the pointer to desyination
 */
char *_strcat(char *des, char *src)
{
	int i, j;

	for (i = 0; des[i] != '\0'; i++)
		;

	for (j = 0; src[j] != '\0'; j++, i++)
		des[i] = src[j];

	des[i] = '\0';
	return (des);
}
/**
 * _strcpy - This is a function that return the copied string to another
 * destrination
 * @des: This is an argument that reprsent the inserted container to copy
 * @src: This is an argument that reprsent the source string to be copied
 *
 * Return: This function return a pointer to the destination
 */
char *_strcpy(char *des, char *src)
{
	int i = 0;

	while (src[i] != '\0')
	{
		des[i] = src[i];
		i++;
	}

	des[i] = '\0';
	return (des);
}
/**
 * _strdup - This is a funxtion that return the duplicated string
 * @str: This is an argument that repsernt the string to be duplicated
 *
 *
 * Return: This is a function that return the pointer to the duplicated string
 */
char *_strdup(char *str)
{
	size_t len;
	char *ptr;

	len = _strlen(str);
	ptr = malloc(sizeof(char) * (len + 1));
	if (ptr == NULL)
		return (NULL);
	_memcpy(ptr, str, len + 1);
	return (ptr);
}
/**
 * _itoa - This is a function that return the converted integer to a string
 * @num: This is an argument that passed the given int number
 *
 * Return: This function return a the given string
 */
char *_itoa(int num)
{
	char *buff;
	int len;
	unsigned int n;

	len = arry_len(num);
	buff = malloc(sizeof(char) * (len + 1));
	if (buff == 0)
		return (NULL);

	buff[len] = '\0';

	if (num < 0)
	{
		n = num * -1;
		buff[0] = '-';
	}
	else
		n = num;

	len--;
	do {
		buff[len] = (n % 10) + '0';
		n = n / 10;
		len--;
	}
	while (n > 0)
		;
	return (buff);
}
/**
 * _strtoken - This is a function that return the tokenize string
 * @str: This is an argument reprsent the given string passed
 * @delim: This is an argument that reprsent the iters to be used
 *
 * Return: This function return the modified string
 */
char *_strtoken(char *str, const char *delim)
{
	char *ptr = NULL;
	static char *s;

	/** validate the value **/
	if (str != NULL)
		s = str;

	if (s != NULL && _strlen(s))
	{
		const size_t len = _strlen((char *)delim);

		/** We run through and skip the constructive delim **/
		while (*s && _memchr(delim, *s, len) != NULL)
			++s;

		/* Check if it is at the beginning of the token **/
		if (*s)
		{
			/* insert the e first no-delim char * **/
			ptr = s;
			while (*s)
			{
				if (_memchr(delim, *s, len) != NULL)
					break;
				else
					++s;
			}
			if (*s)
			{
				s[0] = 0;
				++s;
			}
		}
	}
	return (ptr);
}
