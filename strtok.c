#include "shell.h"
/**
 * _strtok - splits a string based on delimiter given
 * @string: string it takes in
 * @delimiter: specifies set of bytes that delimit the parsed string
 * Authour: Tshupane Morake & Ntuthuko Zimu
 *
 * Return:( token
 */
char *_strtok(char *string, const char *delimiter)
{
	static char *last_String;
	char *_token = 0;

	if (string == NULL && last_String == NULL)
	{
		return (NULL);
	}

	if (string == NULL)
	{
		string = last_String;
	}

	_token = string + _strspn(string, delimiter);
	if (*_token == '\0')
	{
		last_String = NULL;
		return (NULL);
	}

	last_String = _token + _strcspn(_token, delimiter);
	if (*last_String != '\0')
	{
		*last_String++ = '\0';
	}
	return (_token);
}
