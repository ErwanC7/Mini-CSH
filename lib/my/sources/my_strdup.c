/*
** EPITECH PROJECT, 2021
** my_strdup
** File description:
** my_strdup
*/

#include <stdlib.h>

static size_t get_len(char const *str)
{
    size_t i = 0;

    if (str == NULL)
        return 0;
    for (; str[i] != '\0'; ++i);
    return (i);
}

char *my_strdup(char const *str)
{
    char *new = malloc(sizeof(char) * (get_len(str) + 1));
    int i = 0;

    if (str == NULL) {
        new[i] = '\0';
        return (new);
    }
    for (; str[i] != '\0'; ++i)
        new[i] = str[i];
    new[i] = '\0';
    return (new);
}