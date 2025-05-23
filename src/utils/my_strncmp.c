/*
** EPITECH PROJECT, 2025
** my_strncmp
** File description:
** my_strncmp
*/

#include "shell.h"

int my_strncmp(const char *s1, const char *s2, size_t n)
{
    size_t i = 0;

    if (n == 0)
        return (0);
    while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0' && i < n - 1)
        i++;
    return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
