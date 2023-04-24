#include "shell.h"
/**
 * printenv - displays existing enviroment
 *
 * Author: Tshupane Morake & Ntuthuko Zimu
 */
void printenv(void)
{
        unsigned int index = 0;

        while (environ[index])
        {
                puts(environ[index]);
                putchar(10);

                index++;
        }

}
/**
 * get_env - get enviroment variable
 * @name: name to search in the environment
 *
 * return: Pointer for the enviroment value, NULL if the is no match
 */
char *get_env(const char *name)
{
        unsigned int index = 0;
        int difference;
        int variable_length = strlen(name);

        while(environ[index])
        {
                difference = strncmp(environ[index], name, variable_length);
                if (difference == 0)
                        return (environ[index] + variable_length);

                index++;
        }

        return (NULL);
}
/**
 * enviromentLoc - locates variable in the environment
 * @name: name to be located in the environment
 *
 * Return: location in environment on success or -1 on error
 */
int _enviromentLoc(const char *name)
{
	unsigned int index = 0;
        int difference;
        int variable_length = strlen(name);

        while (environ[index])
        {
                difference = strncmp(environ[index], name, variable_length);
                if (difference == 0)
                        return (index);

		index++;
        }

        return (-1);

}
/**
 * _setenv - changes or adds environment variable
 * @name: name of variable added or changed
 * @overwrite: previous value of newly set variable
 *
 * Return: 0 on success -1 on error
 */
int _setenv(const char *name, const char *value, int overwrite)
{
	char *namecopy = strdup(name), *valuecopy = strdup(value);
	int index, length = 0, location = _enviromentLoc(name);
	char **new_environ;
	char *temp = strcat(namecopy, "=");

	free(namecopy);
	namecopy = strcat(temp,valuecopy);
	free(valuecopy);
	free(temp);

	if (location != -1)
	{
		if (overwrite == 0)
			return (0);
		environ[location] = namecopy;
		return (0);
	}

	while (environ[length])
		length++;

	new_environ = malloc(sizeof(*new_environ) * (length + 2));
	if(!new_environ)
	{
		free(namecopy);
		return (-1);
	}
	for(index = 0; index < length; index++)	
		new_environ[index] = environ[index];

	new_environ[index] = namecopy;
	free(namecopy);
	new_environ[index + 1] = NULL;

	free(environ);
	free_array(environ);
	environ = new_environ;

	return (0);
}
/**
 * _unsetenv - deletes the variable name from the environment
 * @name: name of variable to be deleted
 *
 * Return: 0 on success, -1 on error
 */
int _unsetenv(const char *name)
{
	int location = _enviromentLoc(name);
	int i, j, length = 0;
	char **new_environ;

	while (environ[length])
		length++;

	if (location != -1)
	{
		free(environ[location]);
		new_environ = malloc(sizeof(*new_environ) * length);

		j = 0;
		for (i = 0; i < length; i++)
		{
			if (i != location)
			{
				new_environ[i] = environ[j];
				j++;
			}
		}
		new_environ[i] = NULL;

		free(environ);
		free_array(environ);
		environ = new_environ;

	}
	
	return (0);
} 
