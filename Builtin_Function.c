#include "shell.h"
/**
 * main - create a simple shell program
 * Authour: Tshupane Morake & Ntuthuko Zimu
 *
 * Return:0.
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

void print_environment_variables(void)
{
    char **env = environ;
    while (*env != NULL)
    {
        printf("%s\n", *env);
        env++;
    }
}

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
        _setenv("PWD", cwd, 1);
    }
    _setenv("OLDPWD", getenv("PWD"), 1);
}