#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include < stdlib.h>
#include <string.h>
#include <unistd.h>
#include < signal.h>
#include < dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include < errno.h>


/*constants*/
#define PATH_COMMAND 3
#define EXTERNAL_COMMAND 1
#define INTERNAL_COMMAND 2
#define INVALID_COMMAND -1

#define min(x, y) (((x) < (y)) ? (x) : (y))

/**
 * struct map - is a struct that maps command name to a function
 * @command_name: name of the command
 * @function: the function that executes the command
 */

typedef struct map
{
	char *command_name;
	void (*function)(char **command);
}
function_map;

extern char **environ;
extern char *line;
extern char **commands;
extern char *shell_name;
extern int status;

/*helpers*/
void print(char *, int);
char **tokenizer(char *, char *);
void remove_newline(char *);
int _strlen(char *);
void strchr(char *, char *);

/* helpers */
char *_strtok_r(char *, char *, char **);
int _atoi(char *);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void ctrl_c_handler(int);
void remove_comment(char *);

/*helpers*/
int strcmp(char *, char *);
char *_strcat(char *, char *);
int strspn(char *, char *);
char *_strchr(char *, char *);
char *strcspn(char *, char *);

/*utils*/
int parse_command(char *);
void execute_command(char **, int);
char *check_path(char *);
void (*get_func(char *))(char **);
char *_getenv(char *);

/*built_in*/
void env(char **);
void quit(char **);

/*main*/
extern void non_interactive(void);
extern void initializer(char **current_command, int type_command);

#endif SHELL_H
