/*
** EPITECH PROJECT, 2025
** shell
** File description:
** strcat
*/

#include "shell.h"

char *my_strcat(char *dest, char const *src)
{
    int dest_length = 0;
    int src_index = 0;

    if (dest == NULL || src == NULL) {
        return NULL;
    }
    while (dest[dest_length] != '\0') {
        dest_length += 1;
    }
    while (src[src_index] != '\0') {
        dest[dest_length + src_index] = src[src_index];
        src_index += 1;
    }
    dest[dest_length + src_index] = '\0';
    return dest;
}

void remove_newline(char *line)
{
    for (int i = 0; line[i] != '\0'; i++) {
        if (line[i] == '\n') {
            line[i] = '\0';
            break;
        }
    }
}
