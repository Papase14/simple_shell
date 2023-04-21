#include "shell.h"

int main() {
    char input[MAX_LENGTH];
    char *args[MAX_LENGTH];
    char *token;
    int num_args;
    pid_t pid;
    int status, len;

    while (1) {
        printf("cisfun$ ");/*Display prompt*/

        if (!fgets(input, MAX_LENGTH, stdin)) {
            printf("\n");
            break;/*If user presses Ctrl+D, exit the loop.*/
        }

        len = strlen(input);
        if (input[len - 1] == '\n') {
            input[len - 1] = '\0';/*Remove trailing newline*/
        }

        if (strcmp(input, "exit") == 0) {
            break;/*If user enters the "exit" command, break the loop.*/
        }

        num_args = 0;
        token = strtok(input, " ");/*tokenizes the input string and save it*/
        while (token != NULL) {
            args[num_args++] = token;
            token = strtok(NULL, " ");
        }
        args[num_args] = NULL;

	/*Execute the command*/
        pid = fork();
        if (pid == 0) {/*Child process*/
            execve(args[0], args, NULL);
            printf("Error: Command not found\n");
            exit(1);
        } else if (pid < 0) {
            printf("Fork failed\n");
            exit(1);
        } else {/* Parent process*/
            waitpid(pid, &status, 0);
        }
    }

    return 0;
}

