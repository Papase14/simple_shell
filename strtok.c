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
    static char *lastToken = NULL;  /* State variable */
    char *delimiterFound = NULL;
    int tokenLength = 0;
    char *tok = NULL;
    char *start = NULL;

    if (string == NULL || *string == NULL) {
        start = lastToken;
    } else {
        start = *string;
    }

    /*Find the next delimiter*/
    delimiterFound = strstr(start, delimiter);

    /*Calculate the length of the token*/
    if (delimiterFound) {
        tokenLength = delimiterFound - start;
    } else {
        tokenLength = strlen(start);
    }

    /*Allocate memory for the token*/
    tok = malloc(tokenLength + 1);
    if (tok == NULL) {
        return NULL;
    }

    /*Copy the token*/
    memcpy(tok, start, tokenLength);
    tok[tokenLength] = '\0';

    /*Update the state*/
    if (delimiterFound) {
        lastToken = delimiterFound + strlen(delimiter);
    } else {
        lastToken = start + tokenLength;
    }

    /*Update the output parameter*/
    if (string != NULL) {
        *string = lastToken;
    }

    /*Return the token*/
    return tok;
}
