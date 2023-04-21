#include "shell.h"

/**
 * main - create a simple shell program.
 * Author: Tshupane Morak & Ntuthuko Zimu
 *
 * return: 0.
 */
int main(void)
{
	char input[MAX_LENGTH];
	char *args[MAX_LENGTH];
	char *token;
	int num_args, status, len;
	pid_t pid;

	while (1)
	{
		printf("cisfun$ ");/*Display prompt*/

		/*If user presses Ctrl+D, exit the loop.*/
		if (!fgets(input, MAX_LENGTH, stdin))
		{
			printf("\n");
			break;/*If user presses Ctrl+D, exit the loop.*/
		}

		/*Remove trailing newline*/
		len = strlen(input);
		if (input[len - 1] == '\n')
			input[len - 1] = '\0';

		/*If user enters the "exit" command, break the loop.*/
		if (strcmp(input, "exit") == 0)
			break;

		num_args = 0;
		/*tokenizes the input string and save it*/
		token = strtok(input, " ");
		while (token != NULL)
		{
			args[num_args++] = token;
			token = strtok(NULL, " ");
		} args[num_args] = NULL;

		/*Execute the command*/
		pid = fork();
		if (pid == 0)
		{/*Child process*/
			execve(args[0], args, NULL);
			printf("Error: Command not found\n");
			exit(1);
		}
		else if (pid < 0)
		{
			printf("Fork failed\n");
			exit(1);
		}
		else
		{/* Parent process*/
			waitpid(pid, &status, 0);
		}
	} return 0;
}
