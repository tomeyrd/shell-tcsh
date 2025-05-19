/*
** EPITECH PROJECT, 2025
** B-PSU-400-LYN-4-1-ftsh-thomas.saulnier
** File description:
** Builtin commands implementation
*/

#include "shell.h"

int exit_shell(char **words, char **env, char **shell_env)
{
    int exit_code = 0;

    (void)env;
    (void)shell_env;
    if (words[1] == NULL) {
        mini_printf("exit\n");
        exit(0);
    }
    for (int i = 0; words[1][i] != '\0'; i++) {
        if (words[1][i] < '0' || words[1][i] > '9') {
            mini_printf("exit: Expression Syntax.\n");
            return 1;
        }
    }
    for (size_t i = 0; words[1][i] != '\0'; i++) {
        exit_code = exit_code * 10 + (words[1][i] - '0');
    }
    exit(exit_code % 256);
    return EXIT_SUCCESS;
}

int my_cd(char **words, char **env, char **shell_env)
{
    char *dir = NULL;
    char *home = my_getenv("HOME", env);

    (void)shell_env;
    (void)env;
    if (words[1] == NULL) {
        dir = home;
    } else {
        dir = words[1];
    }
    if (dir != NULL && chdir(dir) == -1) {
        return EXIT_ERROR;
    }
    return 0;
}

int print_env(char **words, char **env, char **shell_env)
{
    (void)words;
    (void)env;
    for (int i = 0; shell_env[i] != NULL; i++) {
        mini_printf("%s\n", shell_env[i]);
    }
    return 0;
}
