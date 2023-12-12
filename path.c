#include "shell.h"

/**
 * i_cmd - excutable command
 * @info: input
 * @path: input
 * Return: 1,0
 */

int i_cmd(info_t *info, char *path)
{
	struct stat st;

	(void)info;
	if (!path || stat(path, &st))
		return (0);

	if (st.st_mode & S_IFREG)
	{
		return (1);
	}
	return (0);
}

/**
 * dupp_char - duplicated chars
 * @pathstr: input
 * @start: input
 * @stop: input
 * Return: pointer
 */

char *dupp_char(char *pathstr, int start, int stop)
{
	static char buf[1024];
	int i = 0, k = 0;

	for (k = 0, i = start; i < stop; i++)
		if (pathstr[i] != ':')
			buf[k++] = pathstr[i];
	buf[k] = 0;
	return (buf);
}

/**
 * find_path - find the cmd
 * @info: input
 * @pathstr: input
 * @cmd: input
 * Return: path or NULL
 */

char *find_path(info_t *info, char *pathstr, char *cmd)
{
	int i = 0, curr_pos = 0;
	char *path;

	if (!pathstr)
		return (NULL);
	if ((_strlength(cmd) > 2) && start_by(cmd, "./"))
	{
		if (i_cmd(info, cmd))
			return (cmd);
	}
	while (1)
	{
		if (!pathstr[i] || pathstr[i] == ':')
		{
			path = dupp_char(pathstr, curr_pos, i);
			if (!*path)
				_strconcat(path, cmd);
			else
			{
				_strconcat(path, "/");
				_strconcat(path, cmd);
			}
			if (i_cmd(info, path))
				return (path);
			if (pathstr[i])
				break;
			curr_pos = i;
		}
		i++;
	}
	return (NULL);
}

