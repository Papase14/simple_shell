#include "shell.h"
/**
 * parse_input - takes in user string and tokenizing it
 * @input: user string
 * @num_args:argument number
 *
 * Authour: Tshupane Morake & Ntuthuko Zimu
 *
 * Return:args
*/
char **parse_input(char *input, int *num_args)
{
	char **args = malloc((MAX_LENGTH + 1) * sizeof(char *));
	char *token = _strtok(input, " ");

	while (token != NULL)
	{
		args[*num_args] = token;
		(*num_args)++;
		token = _strtok(NULL, " ");
	}
	args[*num_args] = NULL;
	return (args);
}
/**
 * execute_command - Fork processes
 * @args: tokens
 *
 */
void execute_command(char **args)
{
	pid_t pid = fork();

	if (pid == 0)
	{
		my_execvp(args[0], args);
		_puts("Error: Command not found\n");
		exit(1);
	}
	else if (pid < 0)
	{
		_puts("Fork failed\n");
		exit(1);
	}
	else
	{
		waitpid(pid, NULL, 0);
	}
}

/**
 * free_array - frees array of strings
 * @array: pointer to 2D array of strings
 */
void free_array(char **array)
{
	int i;

	for (i = 0; array[i]; i++)
	{
		free(array[i]);
	}
	free(array);
}

/**
 * my_execvp - function that execute
 * @file: The path of the file to be executed.
 * @argv: An array of strings containing the command-line arguments for the new process.
 */
int my_execvp(const char *file, char *const argv[])
{
	extern char **environ;

	if (execve(file, argv, environ) == -1)
	{
		return (-1);
	} return (0);
}
