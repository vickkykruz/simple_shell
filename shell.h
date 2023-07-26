#ifndef SHELL_PROJECT
#define SHELL_PROJECT

/** Include the header files **/
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <stddef.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <signal.h>
#include <sys/types.h>
#include "global_marcos.h"

/*** PROTOTYPES ***/

/** SHELL_LOOP.C FILE **/
void shell_loop(data_list *list_t);
char *is_shell(data_list *);

/** BUILTIN_FUNC.C FILE **/
int (*get_cmd_fun(char **))(data_list *);

/** _GETLINE.C FILE **/
ssize_t _getline(char **, size_t *, FILE *);
char **get_cmd(data_list *, char *, size_t);
int _set(data_list *);
int _unset(data_list *);

/** _ENV.C FILE **/
char *_getenv(data_list *, char *);
int _env(data_list *);
char *modify_env(data_list *);

/* FUNC1.C FILE **/
char *_strcat(char *, char *);
char *_strcpy(char *, char *);
char *_strdup(char *);
char *_itoa(int);
char *_strtoken(char *, const char *);

/** FUNC2.C FILE */
int _atoi(char *);
int _isdigit(char *);
int _strcmp(char *, char *);
int _strlen(char *);
void *_memchr(register const void *, int, size_t);

/** FUNC3.C FILE **/
void *_realloc(void *, unsigned int, unsigned int);
void _memcpy(void *, const void *, unsigned int);
void insert_line(char **, size_t *n, char *, size_t);
void reverse_str(char *);

/** SEARCH_PROGRAM.C FILE **/
char *find_path(path_list *, char *);
path_list *add_node_end(path_list **, char *);
path_list *path_to_list(data_list *);

/** COMMENT.C FILE **/
int remove_comments(char **);

/** EXPAND.C FILE **/
void expand_variable(data_list *);

/*** CMD_CD.C FILE **/
int cmd_cd_err(data_list *, int);
int _cd(data_list *);
void modify_directory(data_list *, char *, char *);

/** STR_TOKEN.C FULE **/
void solo_sh(data_list *);
int arry_len(int);

/** FREE.C FILE **/
void free_alias(alias_list *);
void free_arr_ptr(char **);
void free_list(path_list *);

/** PRINT.C FILE **/
size_t print_list(const path_list *);
void print_path_dir(void);
int print_alias(data_list *, char *);
int print_alias_list(data_list *);

/** EXIT.C FILE **/
int sh_exit(data_list *);

/* ALIASE.C FILE *** */
alias_list *add_alias(alias_list **, char *, char *);
int _alias(data_list *);
int set_alias(data_list *, char *);
void validate_alias(data_list *);
#endif
