#ifndef _SHELL_H_
#define _SHELL_H_

/* Headers required for the program */
#include <stdio.h>      /*Standard Input/Output library*/
#include <string.h>     /*String manipulation functions*/
#include <stdlib.h>     /*General purpose functions*/
#include <unistd.h>     /*Unix standard functions*/
#include <sys/types.h>  /*Data types used in system calls*/
#include <sys/wait.h>   /*Wait for process termination function*/
#include <sys/stat.h>
#define MAX_LENGTH 1024 /*Maximum length of input string*/

/*Environmental variables*/
extern char **environ;

/*Prototypes*/
char *get_line(FILE *stream);
char *_strtok(char *string,const char *delimiter);
void free_array(char **array);

/* builtin functions */
void printenv(void);
int _setenv(const char *name, const char *value, int overwrite);
int _unsetenv(const char *name);
int _enviromentLoc(const char *name);
char *get_env(const char *name);



#endif

