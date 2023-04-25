#include "shell.h"
/**
 * main - create a simple shell program
 * Authour: Tshupane Morake & Ntuthuko Zimu
 *
 * Return:0.
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
    return args;
}

void execute_command(char **args)
{
    pid_t pid = fork();
    if (pid == 0)
    {
        execvp(args[0], args);
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
	int i = 0;

	while (array[i])
	{
		free(array[i]);
		i++;
	} free(array);
}