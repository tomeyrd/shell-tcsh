/*
** EPITECH PROJECT, 2024
** shell
** File description:
** main
*/

#include "shell.h"

int main(int ac, char **av, char **env)
{
    char **shell_env = init_shell_env(env);

    if (!shell_env) {
        return EXIT_ERROR;
    }
    if (!shell_env) {
        return EXIT_ERROR;
    }
    if (ac == 2 && my_strcmp(av[1], "-h") == 0) {
        usage();
        free_shell_env(shell_env);
        return EXIT_SUCCESS;
    }
    shell_entry(shell_env);
    free_shell_env(shell_env);
    return EXIT_SUCCESS;
}
