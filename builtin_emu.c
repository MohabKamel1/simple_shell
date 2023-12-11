#include "shell.h"

/**
 * _exxit - exit shell
 * @info: input
 * Return: 0
 */

int _exxit(info_t *info)
{
	int exitcheck;

	if (info->argv[1])
	{
		exitcheck = _errstoi(info->argv[1]);
		if (exhitcheck == -1)
		{
			info->status = 2;
			prt_error(info, "Illegal number: ");
			_eputs(info->argv[1]);
			_eputchar('\n');
			return (1);
		}
		info->err_num = _errstoi(info->argv[1]);
		return (-2);
	}
	info->err_num = -1;
	return (-2);
}

/**
 * _cdd - change current directory
 * @info: input
 * Return: 0
 */

int _cdd(info_t *info)
{
	char *s, *dir, buffer[1024];
	int chdir_ret;

	s = getcwd(buffer, 1024);
	if (!s)
		_puts("TODO: >>getcwd failure emsg here<<\n");
	if (!info->argv[1])
	{
		dir = _getenvi(info, "HOME=");
		if (!dir)
			chdir_ret = chdir((dir = _getenvi(info, "PWD="))
					? dir : "/");
		else
			chdir_ret = chdir(dir);
	}
	else if (_strcompar(info->argv[1], "-") == 0)
	{
		if (!_getenvi(info, "OLDPWD="))
		{
			_puts(s);
			_putchar('\n');
			return (1);
		}
		_puts(_getenvi(info, "OLDPWD=")), _putchar('\n');
		chdir_ret = chdir((dir = _getenvi(info, "OLDPWD="))
				? dir : "/");
	}
	else
		chdir_ret = chdir(info->argv[1]);
	if (chdir_ret == -1)
	{
		prt_error(info, "can't cd to ");
		_eputs(info->argv[1]), _eputchar('\n');
	}
	else
	{
		_setenvi(info, "OLDPWD", _getenvi(info, "PWD="));
		_setenvi(info, "PWD", getcwd(buffer, 1024));
	}
	return (0);
}

/**
 * _helpp -  any help
 * @info: input
 * Return: 0
 */

int _helpp(info_t *info)
{
	char **arg_array;

	arg_array = info->argv;
	_puts("help call works. function not yet implemented \n");
	if (0)
		_puts(*arg_array);
	return (0);
}
