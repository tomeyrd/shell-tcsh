/*
** EPITECH PROJECT, 2025
** shell2
** File description:
** get commands
*/

#include "shell.h"

static int is_executable(const char *path)
{
    struct stat st;

    if (stat(path, &st) == 0 && S_ISREG(st.st_mode)
    && access(path, X_OK) == 0) {
        return 1;
    }
    return 0;
}

char *check(const char *cmd)
{
    if (is_executable(cmd)) {
        return my_strdup(cmd);
    }
    return NULL;
}

char *search_dir(const char *dir, const char *cmd)
{
    char *full_path = get_full_path(dir, cmd);
    char *result = NULL;

    if (full_path && is_executable(full_path)) {
        result = full_path;
    } else {
        free(full_path);
        result = NULL;
    }
    return result;
}

static char *search(char *path_copy, const char *cmd)
{
    char *dir = NULL;
    char *full_path = NULL;

    for (dir = strtok(path_copy, ":"); dir; dir = strtok(NULL, ":")) {
        full_path = search_dir(dir, cmd);
        if (full_path != NULL) {
            return full_path;
        }
    }
    return NULL;
}

char *find_cmd(const char *cmd, char **env)
{
    char *path_env = get_path_env(env);
    char *path_copy = NULL;
    char *result = NULL;

    if (path_env) {
        path_copy = my_strdup(path_env);
    } else {
        path_copy = NULL;
    }
    if (abs_path(cmd))
        return check(cmd);
    if (!path_copy)
        return NULL;
    result = search(path_copy, cmd);
    free(path_copy);
    return result;
}
