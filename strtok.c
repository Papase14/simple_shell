#include "shell.h"
/**
 * _strtok - splits a string based on delimiter given
 * @string: string it takes in
 * @delimiter: specifies set of bytes that delimit the parsed string
 * Authour: Tshupane Morake & Ntuthuko Zimu
 *
 * Return: token
 */
char *_strtok(char **string, const char *delimiter)
{
    char *start;
    char *tok;
    
    if (*string == NULL) {
        return NULL;
    }
    
    /*Find the start of the next token*/
    start = *string;
    while (*start && strchr(delimiter, *start)) {
        start++;
    }
    
    if (!*start) {
        /*No more tokens*/
        *string = NULL;
        return NULL;
    }
    
    /*Find the end of the current token*/
    tok = start;
    while (*tok && !strchr(delimiter, *tok)) {
        tok++;
    }
    
    if (*tok) {
        /*Terminate the current token*/
        *tok = '\0';
        /*Set the pointer to the next token*/
        *string = tok + 1;
    } else {
        /*No more tokens*/
        *string = NULL;
    }
    
    return start;
}

