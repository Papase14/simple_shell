#include "shell.h"
/**
 * _str_tok - splits a string based on delimiter given
 * @string: string it takes in
 * @delimiter: specifies set of bytes that delimit the parsed string
 * Authour: Tshupane Morake & Ntuthuko Zimu
 *
 * Return: token
 */
char *_strtok(char *string, const char *delimiter)
{
    static char *lastString = NULL;
    char *tok = NULL;

    if (string == NULL && lastString == NULL) {
        return NULL;
    }

    if (string == NULL) {
        string = lastString;
    }

    tok = string + strspn(string, delimiter);

    /*if reachs the end of the string, return NULL*/
    if (*tok == '\0') {
        lastString = NULL;
        return NULL;
    }

    lastString = tok + strcspn(tok, delimiter);

    if (*lastString != '\0') {
        *lastString++ = '\0';
    }

    return tok;
}

