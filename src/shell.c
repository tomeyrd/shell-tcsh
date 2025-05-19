/*
** EPITECH PROJECT, 2025
** shell
** File description:
** shell.c
*/

#include "shell.h"

void pid(char **words, char **shell_env)
{
    pid_t p = fork();
    int status;
    char *path = NULL;

    if (p == -1)
        exit(EXIT_ERROR);
    if (p == 0) {
        path = find_cmd(words[0], shell_env);
        if (!path) {
            mini_printf("%s: Command not found\n", words[0]);
        }
        execve(path, words, shell_env);
        free(path);
        exit(1);
    } else {
        waitpid(p, &status, 0);
        program_status(status, p);
    }
}
