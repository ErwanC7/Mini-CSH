/*
** EPITECH PROJECT, 2021
** my_strcmp
** File description:
** compare tow strings
*/

#include <stdlib.h>

static unsigned int get_len(char const *str)
{
    unsigned int i = 0;

    for (; str[i] != '\0'; ++i);
    return (i);
}

int my_strcmp(char const *str, char const *cmp)
{
    unsigned int i = 0;

    if (str == NULL)
        return (-1);
    for (; str[i] != '\0' && cmp[i] != '\0'; ++i) {
        if (str[i] != cmp[i])
            return (-1);
    }
    if (i == 0 || i < get_len(cmp) || str[i] != '\0')
        return (-1);
    return (0);
}

int my_strncmp(char const *str, char const *cmp, unsigned int n)
{
    unsigned int i = 0;

    for (unsigned int j = 0; str[i] != '\0' && cmp[i] != '\0' && j < n; ++i) {
        if (str[i] != cmp[i])
            return (-1);
    }
    if (i == 0 || i != n)
        return (-1);
    return (0);
}