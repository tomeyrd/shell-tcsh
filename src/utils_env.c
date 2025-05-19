/*
** EPITECH PROJECT, 2025
** shell
** File description:
** env utils
*/

#include "shell.h"

void free_shell_env(char **shell_env)
{
    int i = 0;

    if (!shell_env)
        return;
    for (i = 0; shell_env[i]; i++)
        free(shell_env[i]);
    free(shell_env);
}

static void free_new_env(int i, char **new_env)
{
    for (int j = 0; j < i; j++) {
        free(new_env[j]);
    }
    free(new_env);
}

char **init_shell_env(char **env)
{
    int count = 0;
    char **new_env;

    if (!env)
        return NULL;
    while (env[count])
        count++;
    new_env = malloc(sizeof(char *) * (count + 1));
    if (!new_env)
        return NULL;
    for (int i = 0; i < count; i++) {
        new_env[i] = my_strdup(env[i]);
        if (!new_env[i]) {
            free_new_env(i, new_env);
            return NULL;
        }
    }
    new_env[count] = NULL;
    return new_env;
}
