#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>

#define READ_BUF_SIZE 1024
#define WRITE_BUF_SIZE 1024
#define BUF_FLUSH -1

#define CMD_NORM 0
#define CMD_OR 1
#define CMD_AND 2
#define CMD_CHAIN 3

#define CONVERT_LOWERCASE 1
#define CONVERT_UNSIGNED 2

#define USE_GETLINE 0
#define USE_STRTOK 0

#define HIST_FILE ".simple_shell_history"
#define HIST_MAX 4096

extern char **environ;

/**
 * struct liststr - linked list
 * @num: input
 * @str: input
 * @next: input
 */

typedef struct liststr
{
	int num;
	char *str;
	struct liststr *next;
} list_t;

/**
 * struct passinfo - pseudo arguments
 * @arg: input
 * @argv: input
 * @path: input
 * @argc: input
 * @line_count: input
 * @err_num: input
 * @linecount_flag: input
 * @fname: input
 * @env: input
 * @environ: input
 * @history: input
 * @alias: input
 * @env_changed: input
 * @status: input
 * @cmd_buf: input
 * @cmd_buf_type: input
 * @readfd: input
 * histcount: input
 */

typedef struct passinfo
{
	char *arg;
	char **argv;
	char *path;
	int argc;
	unsigned int line_count;
	int err_num;
	int linecount_flag;
	char *fname;
	list_t *env;
	list_t *history;
	list_t *alias;
	char **environ;
	int env_changed;
	int status;
	char **cmd_buf;
	int cmd_buf_type;
	int readfd;
	int histcount;
} info_t;

#define INFO_INIT \
{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, \
	0, 0, 0}

/**
 * struct builtin _ builtin string
 * @type: input
 * @func: input
 */

typedef struct builtin
{
	char *type;
	int (*func)(info_t *);
} builtin_table;

int hsh(info_t *, char **);
int find_builtin(info_t *);
void find_cmd(info_t *);
void fork_cmd(info_t *);

int is_cmd(info_t *, char *);
char *dup_chars(char *, int , int);
char *find_path(info_t *, char *, char *);

int loophsh(char **);

void _eputs(char *);
int _eputchar(char);
int _putdf(char c, int df);
int _putsfd(char *str, int df);

int _strlength(char *);
int _strcompar(char *, char *);
char *starts_by(const char *, const char *);
char *_strconcat(char *, char *);

char *_strcppy(char *, char *);
char *_strdupp(const char *);
void _prt(char *);
int _putchar(char);

char *_strncppy(char *, char *, int);
char *_strnconcat(char *, char *, int);
char *_strchar(char *, char *);

char **strpw(char *, char *);
char **strpw2(char *, char *);
