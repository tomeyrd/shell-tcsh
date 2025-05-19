/*
** EPITECH PROJECT, 2025
** shell
** File description:
** user input
*/

#include "shell.h"

const command_t commands[] = {
    {"env", print_env},
    {"exit", exit_shell},
    {"cd", my_cd},
    {NULL, NULL}
};

void if_value(int i, char **words, char *value)
{
    if (value) {
        words[i] = my_strdup(value);
    }
}

void expand_variables(char **words, char **shell_env)
{
    char *var_name = NULL;
    char *value = NULL;
    int i = 0;

    for (; words[i]; i++) {
        if (words[i][0] == '$') {
            var_name = words[i] + 1;
            value = my_getenv(var_name, shell_env);
            if_value(i, words, value);
        }
    }
}

void verify_entry(char **words, char **shell_env)
{
    if (!words || !words[0])
        return;
    expand_variables(words, shell_env);
    for (int i = 0; commands[i].name != NULL; i++) {
        if (my_strcmp(words[0], commands[i].name) == 0) {
            commands[i].func(words, shell_env, shell_env);
            return;
        }
    }
    pid(words, shell_env);
}

void shell_entry(char **shell_env)
{
    char **words;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    while (1) {
        mini_printf("$> ");
        read = getline(&line, &len, stdin);
        if (read == -1)
            break;
        remove_newline(line);
        words = stwa(line, " \t");
        if (words[0] != NULL)
            verify_entry(words, shell_env);
        free(words);
    }
    free(line);
}
