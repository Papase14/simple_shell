#include "shell.h"
/**
 * _strtok - splits a string based on delimiter given
 * @string: string it takes in
 * @delimiter: specifies set of bytes that delimit the parsed string
 * Authour: Tshupane Morake & Ntuthuko Zimu
 *
 * Return: token
 */
unisigned int is_delimiter(char c, char *delimiter)
{
	while (*delimiter != '\0')
	{
		if (c == *delimiter)
			return 1;

		delimiter++;
	}
	
	return 0;
}
char *_strtok(char *string, char *delimiter)
{
	static char *backup_string; // start of the next search
	
	if (!string)
		string = backup_string;

	if(!string)
		return NULL; //bad user
	
	//handle beginning of the sting containing delims
	
	while (1)
	{
		if (is_delimiter(string, delimiter))
		{
			string++;
			continue;
		}
		
		if (string == '\0')
		{
			//we've reached the end if the string
			return NULL;
		}
		break;
	}

	char *ret = string;

	while (1)
	{
		if (string == '\0')
		{
			/*end of the input strinf and next exec will return NULL*/
			backup_string = string;
			return ret;
		}
		
		if (is_delimiter(*string, delimiter))
		{
			*string = '\0';
			backup_string = string + 1;
			return ret;
		}
		
		string++;
	}
}
