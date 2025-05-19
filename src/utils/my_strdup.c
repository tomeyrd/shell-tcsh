/*
** EPITECH PROJECT, 2025
** shell
** File description:
** strcup
*/

#include "shell.h"

size_t m_strlen(const char *str)
{
    size_t len = 0;

    if (!str)
        return 0;
    while (str[len] != '\0')
        len++;
    return len;
}

char *my_strdup(const char *src)
{
    size_t len;
    char *dest;

    if (!src)
        return NULL;
    len = m_strlen(src);
    dest = malloc(len + 1);
    if (!dest)
        return NULL;
    for (size_t i = 0; i < len; i++)
        dest[i] = src[i];
    dest[len] = '\0';
    return dest;
}
