/*
** EPITECH PROJECT, 2025
** shell
** File description:
** status of cmd
*/

#include "shell.h"

int segfault_status(int status)
{
    if (WIFSTOPPED(status)) {
        return 84;
    }
    return 0;
}

void program_status(int status, pid_t pid)
{
    const char *sig_name = NULL;
    int sig_num;

    (void)pid;
    if (WIFSIGNALED(status)) {
        sig_num = WTERMSIG(status);
        sig_name = strsignal(sig_num);
        mini_printf("%s\n", sig_name);
        status = 128 + sig_num;
    }
}
