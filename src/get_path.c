/*
** EPITECH PROJECT, 2025
** path.c
** File description:
** path oh shell cmd
*/

#include "shell.h"

char *get_full_path(const char *dir, const char *cmd)
{
    char *full_path;
    size_t dir_len = my_strlen(dir);
    size_t cmd_len = my_strlen(cmd);

    full_path = malloc(dir_len + cmd_len + 2);
    if (!full_path)
        return NULL;
    my_strcpy(full_path, dir);
    my_strcat(full_path, "/");
    my_strcat(full_path, cmd);
    return full_path;
}

int abs_path(const char *cmd)
{
    return my_strchr(cmd, '/') != NULL;
}
