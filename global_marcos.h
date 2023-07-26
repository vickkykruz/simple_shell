#ifndef GLOBAL_MARCOS
#define GLOBAL_MARCOS

/* Rename global datatype*/
typedef int integer;
/*typedef char* string;*/
typedef float decimal;
typedef long long_number;

#define BUFF_SIZE 1024
#define NEW_LINE '\n'
#define DELIME_LIST " \t\n\a\r"
extern char **environ;

/**
 * struct path - This is a struct the contains the data path linked list
 * @str_path: This is an argument that contain the path string
 * @next: This is an argument that contain the informat of the next list
 * Description: This struct is allows us the store or hold the command path
 *              list called by the user
 */
typedef struct path
{
	char *str_path;
	struct path *next;
} path_list;

/**
 * struct alias - This is a struct that contains the data alias linked list
 * @str: This is an argument that conatin the name information of the list
 * @val: This is an argrument that contain the value of the linked list
 * @next: This is an argument that contain thebnext informatbof the list
 * Description: This struct all the user to store the alias information
 * passed by the program
 */
typedef struct alias
{
	char *str;
	char *val;
	struct alias *next;
} alias_list;

/**
 * struct data_into - This struct contain the information of the shell data
 * @arv: This is an argument that conatin argument vector string
 * @arg_line: This is an argument that conatin the command line of the shell
 * @env: This is an argument that contain the shell environment
 * @arry: This is an argument that conatins an array of ech argument entered
 * into the shel
 * @builtin: This is an argument that check if the last command wqs run in
 * the builtin command
 * @intact: This is an argument that conatin statuscode (1) if interactive
 * or (0) if not interactive
 * @path: This is an argument that conatin the PATH variable
 * @list_alias: This is an argument that the current shell session
 * @status: This is an argument that cobtain the shell status shell
 * @pid: This is an argument that conatins process id of the shell
 * @len: This is an argument that contain the lenght of the line
 * Description: This is a linked list that hold or store the shell inform
 * passed but the program and the user
 */
typedef struct data_into
{
	char **arv;
	char *arg_line;
	char **env;
	char **arry;
	int builtin;
	int intact;
	path_list *path;
	alias_list *list_alias;
	int status;
	pid_t pid;
	ssize_t len;
} data_list;

/**
 * struct buitin - This is a struct that conatin the builtin information
 * @cmd: This is an aargument that conatin the command passed
 * @fun: This is an argument that contain the function of the command
 * Description: This struct is used to connect to the coomand linked to the
 * list
 */
typedef struct buitin
{
	char *cmd;
	int (*fun)(data_list *);
} builtin_fun;

#define PLACEHOLDRS \
	{ NULL, NULL, 0, NULL, 0, NULL, NULL, NULL }

#define HEX {"0123456789abcdef"

#define BUITIN_FUNC {\
	{"cd", _cd},\
	{"env", _env},\
	{"setenv", _set},\
	{"unsetenv", _unset},\
	{"exit", sh_exit},\
	{"alias", _alias},\
	{NULL, NULL} \
}
#endif
