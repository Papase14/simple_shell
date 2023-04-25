#include "shell.h"
/**
 * handle_exit_command - function that exits shell
 * @input: exit key word
 *
 * Authour: Tshupane Morake & Ntuthuko Zimu
 *
*/
void handle_exit_command(char *input)
{
	if (_strncmp(input, "exit ", 5) == 0)
	{
		int exit_status = _atoi(input + 5);

		exit(exit_status);
	}
	else if (_strcmp(input, "exit") == 0)
	{
		exit(0);
	}
}

/**
 * print_environment_variables - displays current environment
 *
 */
void print_environment_variables(void)
{
	char **env = environ;

	while (*env != NULL)
	{
		printf("%s\n", *env);
		env++;
	}
}

/**
 * change_directory - changes directory
 * @input: input from user
 */
void change_directory(char *input)
{
	char *dir_path = input + 3;
	char cwd[MAX_LENGTH];

	if (_strcmp(dir_path, "-") == 0)
	{
		chdir(getenv("OLDPWD"));
	}
	else if (strlen(dir_path) == 0)
	{
		chdir(getenv("HOME"));
	}
	else
	{
		if (chdir(dir_path) == -1)
		{
			_puts("Error: Unable to change directory\n");
		}
	}

	if (getcwd(cwd, sizeof(cwd)) != NULL)
	{
		setenv("PWD", cwd, 1);
	}
}