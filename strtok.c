#include "shell.h"
/**
 * strtok - splits a string based on delimiter given
 * @string: string it takes in
 * @delimiter: specifies set of bytes that delimit the parsed string
 * Authour: Tshupane Morake & Ntuthuko Zimu
 *
 * Return: token
 */
char *_strtok(char** string, const char* delimiters)
{
    char* str = *string;
    char* tok_start;

    if (!str)
        return NULL;

    /*skip leading delimiters*/
    while (*str && strchr(delimiters, *str))
        ++str;

    if (!*str)
        return NULL;

    /*find end of token*/
    tok_start = str;
    while (*str && !strchr(delimiters, *str))
        ++str;

    /*replace delimiter with null terminator*/
    if (*str)
        *str++ = '\0';

    *string = str;
    return tok_start;
}
