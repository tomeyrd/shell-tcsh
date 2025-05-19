/*
** EPITECH PROJECT, 2025
** shell1
** File description:
** env cmd
*/

#include "shell.h"

char *my_getenv(const char *name, char **env)
{
    size_t len = my_strlen(name);

    if (name == NULL || env == NULL) {
        return NULL;
    }
    for (int i = 0; env[i] != NULL; i++) {
        if (my_strncmp(env[i], name, len) == 0 && env[i][len] == '=') {
            return env[i] + len + 1;
        }
    }
    return NULL;
}

char *get_path_env(char **env)
{
    for (int i = 0; env[i]; i++) {
        if (my_strncmp(env[i], "PATH=", 5) == 0) {
            return env[i] + 5;
        }
    }
    return NULL;
}
