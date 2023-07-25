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
  data_list list_t;
  int i = 0;
  
  list_t.arg_line = NULL;
  list_t.len = 0;
  list_t.intact = 1;
  list_t.pid = getpid();
  list_t.status = 0;
  list_t.builtin = 0;
  list_t.arry = NULL;
  list_t.list_alias = NULL;
  (void) env;
  
  list_t.arv = malloc(sizeof(char *) * (argc + 1));
  while (argv[i])
    {
      list_t.arv[i] = _strdup(argv[0]);
      i++;
    }
  list_t.arv[i] = NULL;
  
  /* Gather each number of the env strings */
  for (i = 0; environ[i]; i++)
    ;
  
  list_t.env = malloc(sizeof(char *) * (i + 1));
  /** Store each index to the env strict **/
  for (i = 0; environ[i]; i++)
    list_t.env[i] = _strdup(environ[i]);
  list_t.env[i] = NULL;
  
  list_t.path = path_to_list(&list_t);
  shell_loop(&list_t);
  
  return (0);
}
