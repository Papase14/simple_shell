#include "shell.h"
/**
 * _str_tok - splits a string based on delimiter given
 * @string: string it takes in
 * @delimiter: specifies set of bytes that delimit the parsed string
 * Authour: Tshupane Morake & Ntuthuko Zimu
 *
 * Return: token
 */
char *_strtok(char **string, char *delimiter)
{
    char *_string = *string;
    char *delimiterFound = (char*)0; /*Type casting*/
    int tokenLength = 0;
    char *tok = (char*)0;

    if(!_string)
        return ((char*)0);

    delimiterFound = strstr(_string, delimiter);

    if (delimiterFound)
    {
        tokenLength = delimiterFound - _string;
    }
    else
    {
        tokenLength = strlen(_string);
    }
    
    tok = malloc(tokenLength + 1);
    memcpy(tok, string, tokenLength);
    tok[tokenLength] = '\0';

    *string = delimiterFound ? delimiterFound + strlen(delimiter) : (char*)0;

    return (tok);
}
