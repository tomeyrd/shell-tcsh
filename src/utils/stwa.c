/*
** EPITECH PROJECT, 2025
** stwa
** File description:
** stwa
*/

#include "shell.h"

static int is_delim(char c, char *delim)
{
    for (int i = 0; delim[i] != '\0'; i++) {
        if (c == delim[i])
            return 1;
    }
    return 0;
}

static int count_words(char *str, char *delim)
{
    int count = 0;
    int in_word = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (!is_delim(str[i], delim) && in_word == 0) {
            in_word = 1;
            count++;
        }
        if (is_delim(str[i], delim))
            in_word = 0;
    }
    return count;
}

static char *get_next_word(char *str, int *index, char *delim)
{
    int start = *index;
    int length = 0;
    char *word;

    while (str[*index] && !is_delim(str[*index], delim)) {
        (*index)++;
        length++;
    }
    word = malloc(sizeof(char) * (length + 1));
    if (!word)
        return NULL;
    for (int i = 0; i < length; i++)
        word[i] = str[start + i];
    word[length] = '\0';
    while (str[*index] && is_delim(str[*index], delim))
        (*index)++;
    return word;
}

char **stwa(char *str, char *delim)
{
    int words_count = 0;
    char **array = NULL;
    int index = 0;

    if (!str || !delim)
        return NULL;
    words_count = count_words(str, delim);
    array = malloc(sizeof(char *) * (words_count + 1));
    if (!array)
        return NULL;
    while (str[index] && is_delim(str[index], delim))
        index++;
    for (int i = 0; i < words_count; i++)
        array[i] = get_next_word(str, &index, delim);
    array[words_count] = NULL;
    return array;
}
