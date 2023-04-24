#include "shell.h"
/**
 * main - create a simple shell program
 * Authour: Tshupane Morake & Ntuthuko Zimu
 *
 * Return:0.
*/
int main(void)
{
	char *input[MAX_LENGTH]; /*Character array to hold user input*/
	char *args[MAX_LENGTH]; /*Array to hold arguments*/
	char *token;            /*Pointer to current token*/
	pid_t pid;              /*Process ID variable*/
	int num_args, status, len;

	while (1)
	{
		printf("cisfun$ "); /*Display prompt*/

		input = get_line(stdin); /*Get input from user*/
		if (!input)
		{
			printf("\n");
			break;
		}

		len = strlen(input);
		if (input[len - 1] == '\n')
			input[len - 1] = '\0'; /*Remove trailing newline*/

		if (strcmp(input, "exit") == 0)
		{
			/*if user enters "exit" command with an argument*/
			if (num_args == 2)
			{
				status = atoi(args[1]); /*convert the argument to an integer*/
				exit(status); /*exit the shell with the provided exit status*/
			}
			else if (num_args > 2)
			{
				/*if there are too many arguments, print an error message*/
				printf("Error: too many arguments\n");
			}
			else
			{
				break; /*if no argument is provided, break out of the loop*/
			}
		}
		else if (strcmp(input, "env") == 0) /*check if user entered "env" command*/
		{
			/*print the current environment variables*/
			char **env = environ;
			while (*env != NULL)
			{
				printf("%s\n", *env);
				env++;
			} free(input);
			continue;
		}

		num_args = 0; /*Initialize number of arguments to 0*/
		token = _strtok(input, " "); /*Get first token from input string*/
		while (token != NULL)
		{
			args[num_args++] = token;
			token = _strtok(NULL, " ");
		} args[num_args] = NULL;

		pid = fork(); /*Create child process*/
		if (pid == 0)
		{
			execvp(args[0], args); /*Execute command*/
			printf("Error: Command not found\n");
			exit(1);
		} else if (pid < 0)
		{
			printf("Fork failed\n");
			exit(1);
		}
		else /*If parent process*/
		{
			waitpid(pid, &status, 0); /*Wait for child process to terminate*/
		}
		free(input);
	}
	return 0;
}
