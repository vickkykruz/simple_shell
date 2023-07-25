#include "shell.h"
/***/
int sh_exit(data_list *list_t)
{
	int statusCode;

	statusCode = list_t->status;
	if (list_t->intact == 1)
	{
		if (!_strcmp("exit", list_t->arry[0]) && list_t->arry[1])
		{
			list_t->status = _atoi(list_t->arry[1]);
			statusCode = list_t->status;
		}
	}
	if (list_t->path)
		free_list(list_t->path);
	if (list_t->list_alias)
		free_alias(list_t->list_alias);
	if (list_t->arv)
		free_arr_ptr(list_t->arv);
	if (list_t->env)
		free_arr_ptr(list_t->env);
	if (list_t->arry && list_t->intact == 1)
		free_arr_ptr(list_t->arry);
	if (list_t->arg_line)
		free(list_t->arg_line);

	exit(statusCode);
}
