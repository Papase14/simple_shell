#include "shell.h"
/**
 * main - create a simple shell program
 * Authour: Tshupane Morake & Ntuthuko Zimu
 *
 * Return:0.
*/
int main(void)
{
	char **args, *input;
	int num_args;

	while (1)
	{
		puts("cisfun$ ");
		input = get_line(stdin);

		if (!input)
		{
			break;
		}
		handle_exit_command(input);

		if (_strcmp(input, "env") == 0)
		{
			print_environment_variables();
			free(input);
			continue;
		}

		if (_strncmp(input, "cd ", 3) == 0)
		{
			change_directory(input);
			free(input);
			continue;
		}

		num_args = 0;
		args = parse_input(input, &num_args);
		execute_command(args);
		free(args);
		free(input);
	}
	return (0);
}
