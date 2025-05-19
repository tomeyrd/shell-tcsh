/*
** EPITECH PROJECT, 2025
** struct.h
** File description:
** struct.h
*/

#include "shell.h"

#ifndef STRUCT_H
    #define STRUCT_H

typedef int (*command_func_t)(char **, char **, char **);

typedef struct shell_state_s {
    char **env;
} shell_state_t;


typedef struct command_s {
    const char *name;
    int (*func)(char **, char **, char **);
} command_t;

#endif /* !STRUCT_H */
