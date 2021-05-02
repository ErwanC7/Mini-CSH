/*
** EPITECH PROJECT, 2021
** my_concat
** File description:
** concat two strings
*/

#include <stdlib.h>
#include <stdio.h>

static size_t get_len(char const *str)
{
    size_t i = 0;

    for (; str[i] != '\0'; ++i);
    return (i);
}

char *my_concat(char const *cat, char const *str, char c)
{
    size_t size = get_len(cat) + get_len(str);
    char *new = malloc(sizeof(char) * (size + 2));
    int j = 0;

    for (int i = 0; cat[i] != '\0'; ++i, ++j)
        new[j] = cat[i];
    if (c != '\0')
        new[j++] = c;
    for (int i = 0; str[i] != '\0'; ++i, ++j)
        new[j] = str[i];
    new[j] = '\0';
    return (new);
}