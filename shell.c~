#include "shell.h"
/**
 * main - This function is an eniry function of the program
 * @argc: This is an argument that represent the number of argument passed int
 * the command line
 * @argv: This is an argument that represent the vector string of an argumment
 * passed in the command line
 * 
 * Return: This function return an EXITSUCESS
*/
integer main(integer argc, string argv[], string env[])
{
	data_list list_t = {NULL}, *ptr;
	string prompt = "$ ";

	/* Pass the address of  of the list_t to ptr */
	ptr = &list_t;

	/** intialize the data info **/
	intialize_info(ptr, argc, argv, env);

	if (isatty(STDIN_FILENO) && isatty(STDOUT_FILENO) && argc == 1)
		errno = 2;

	errno = 0; /* Return the status to default */
	/* Create a inifite loop */
	shell_loop(prompt, ptr);
    
	return (0);
}
