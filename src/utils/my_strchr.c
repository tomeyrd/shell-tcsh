/*
** EPITECH PROJECT, 2025
** my_strchr
** File description:
** my_strchr
*/

#include "shell.h"

char *my_strchr(const char *str, char c)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == c) {
            return (char *)(str + i);
        }
    }
    return NULL;
}
