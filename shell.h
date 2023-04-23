#ifndef _SHELL_H_
#define _SHELL_H_

/* Headers required for the program */
#include <stdio.h>      /*Standard Input/Output library*/
#include <string.h>     /*String manipulation functions*/
#include <stdlib.h>     /*General purpose functions*/
#include <unistd.h>     /*Unix standard functions*/
#include <sys/types.h>  /*Data types used in system calls*/
#include <sys/wait.h>   /*Wait for process termination function*/

#define MAX_LENGTH 1024 /*Maximum length of input string*/

/*Environmental variables*/
extern char **environ;

/*Prototypes*/
char *get_line(FILE *stream);
char *my_strtok(char* _strin, const char* delim);


#endif

