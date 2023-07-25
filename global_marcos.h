#ifndef GLOBAL_MARCOS
#define GLOBAL_MARCOS

/* Rename global datatype*/
typedef int integer;
typedef char * string;
typedef float decimal;
typedef long long_number;

#define BUFF_SIZE 1024
#define NEW_LINE '\n'
#define DELIME_LIST " \t\n\a\r"
extern string *environ;

/***/
typedef struct path
{
	string str_path;
	struct path *next;
} path_list;

/***/
typedef struct alias
{
	string str;
	string val;
	struct alias *next;
} alias_list;

/**
 * struct data_info - created the sturct to store the argument entered
 * @arg: This is an argumen
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


/**/
typedef struct buitin
{
	char * cmd;
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
	{NULL, NULL}\
}
#endif
