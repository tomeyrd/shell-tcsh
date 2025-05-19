/*
** EPITECH PROJECT, 2025
** shell
** File description:
** str copy
*/

#include "shell.h"

char *my_strcpy(char *dest, char const *src)
{
    int i = 0;

    if (dest == NULL || src == NULL) {
        return NULL;
    }
    while (src[i] != '\0') {
        dest[i] = src[i];
        i += 1;
    }
    dest[i] = '\0';
    return dest;
}
