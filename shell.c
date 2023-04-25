#include "shell.h"
/**
 * main - create a simple shell program
 * Authour: Tshupane Morake & Ntuthuko Zimu
 *
 * Return:0.
*/
int main(void)
{
	char *input, *args[MAX_LENGTH], *token;
	pid_t pid;
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

		if (strncmp(input, "exit ", 5) == 0)
		{
    		int exit_status = atoi(input + 5);
    		exit(exit_status);  /*if user enters "exit 98", exits the loop with 98 status*/
		}
		else if (strcmp(input, "exit") == 0)
		{
    		break; /*if user enters "exit" break out of loop*/
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
		else if (strncmp(input, "cd ", 3) == 0) /* check if user entered "cd" command*/
        {
            /* get the directory path to change to */
            char *dir_path = input + 3;
            if (strcmp(dir_path, "-") == 0) /* check if directory is '-' */
            {
                /* change to previous directory */
                chdir(getenv("OLDPWD"));
            }
            else if (strlen(dir_path) == 0) /* check if no directory path is given */
            {
                /* change to home directory */
                chdir(getenv("HOME"));
            }
            else /* change to specified directory path */
            {
                if (chdir(dir_path) == -1)
                {
                    printf("Error: Unable to change directory\n");
                }
            }
            /* update PWD environment variable */
            char cwd[MAX_LENGTH];
            if (getcwd(cwd, sizeof(cwd)) != NULL)
            {
                setenv("PWD", cwd, 1);
            }
            /* update OLDPWD environment variable */
            setenv("OLDPWD", getenv("PWD"), 1);
            free(input);
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
