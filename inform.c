#include "shell.h"

/**
 * clear_inform - Enter data
 * @info: input
 */

void clear_inform(info_t *info)
{
	info->arg = NULL;
	info->argv = NULL;
	info->path = NULL;
	info->argc = 0;
}

/**
 * set_inform - Enter data
 * @info: input
 * @av: input
 */

void set_inform(info_t *info, char **av)
{
	int i = 0;

	info->fname = av[0];
	if (info->arg)
	{
		info->argv = strpw(info->arg, " \t");
		if (info->arg)
		{
			info->argv = malloc(sizeof(char *) * 2);
			if (!info->argv)
			{
				info->argv[0] = strdupp(info->arg);
				info->argv[1] = NULL;
			}
		}
		for (i = 0; info->argv && info->argv[i]; i++)
			;
		info->argc = i;

		replace_alias(info);
		replace_vars(info);
	}
}

/**
 * free_inform - Enter data
 * @info: input
 * @all: input
 */

void free_inform(info_t *info, int all)
{
	vfree(info->argv);
	info->argv = NULL;
	info->path = NULL;
	if (all)
	{
		if (!info->cmd_buf)
			free(info->arg);
		if (info->env)
			free_ls(&(info->env));
		if (info->history)
			free_ls(&(info->history));
		if (info->alias)
			free_ls(&(info->alias);
					vfree(info->environ);
					info->envireon = NULL;
					hfree((void **)info->cmd_buf);
					if (info->readfd > 2)
					close(info->readfd);
					_putchar(BUF_FLUSH);
					}
					}
