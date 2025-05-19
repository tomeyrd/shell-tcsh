/*
** EPITECH PROJECT, 2025
** shell
** File description:
** shell.h
*/

#ifndef SHELL_H
    #define SHELL_H

    #include <string.h>
    #include <unistd.h>
    #include <stddef.h>
    #include <stdlib.h>
    #include <stdio.h>
    #include <stdarg.h>
    #include <stdio.h>
    #include <fcntl.h>
    #include <sys/wait.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <sys/resource.h>
    #include <stdbool.h>
    #include <errno.h>
    #include "struct.h"

    #define EXIT_ERROR 84
    #define EXIT_SUCCESS 0

void free_shell_env(char **shell_env);
char **get_shell_env(void);
char *get_full_path(const char *dir, const char *cmd);
int abs_path(const char *cmd);
char *get_path_env(char **env);
char *my_strchr(const char *str, char c);
int my_strncmp(const char *s1, const char *s2, size_t n);
void remove_newline(char *line);
int exit_shell(char **words, char **env, char **shell_env);
int my_cd(char **words, char **env, char **shell_env);
char **init_shell_env(char **env);
typedef int (*command_func_t)(char **words, char **env, char **shell_env);
char *my_getenv(const char *name, char **env);
char *find_cmd(const char *cmd, char **env);
char *my_strcat(char *dest, const char *src);
char *my_strcpy(char *dest, const char *src);
char *my_strdup(const char *src);
int segfault_status(int status);
void program_status(int status, pid_t pid);
void pid(char **words, char **shell_env);
void shell_entry(char **shell_env);
int print_env(char **words, char **env, char **shell_env);
char **stwa(char *str, char *delim);
int my_strcmp(const char *s1, const char *s2);
int usage(void);
int mini_printf(const char *str, ...);
char *my_strcpy(char *dest, char const *src);
void my_putchar(char c);
int my_put_nbr(int nb);
int my_putstr(char const *str);
int my_strlen(char const *str);
#endif /* !SHELL_H */
