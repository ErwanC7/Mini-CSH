/*
** EPITECH PROJECT, 2021
** minishell1
** File description:
** minishell1
*/

#include <stdlib.h>
#include <string.h>
#include "../include/my.h"

static size_t get_index(char const *buffer, char c)
{
    size_t nbr = 1;

    for (int i = 0;buffer[i] != '\0'; i++) {
        if (buffer[i] == c)
            nbr += 1;
    }
    return (nbr);
}

char **str_to_word_array(char *buffer, char const *c)
{
    size_t size = get_index(buffer, c[0]);
    char **str = malloc(sizeof(char *) * (size + 1));
    char *cp;

    if (buffer[0] == '\0') {
        str[0] = malloc(sizeof(char *) * 1);
        str[0][0] = '\0';
        str[1] = NULL;
        return (str);
    }
    cp = my_strdup(buffer);
    str[0] = my_strdup(strtok(cp, c));
    for (unsigned int i = 1; i < size; ++i)
        str[i] = my_strdup(strtok(NULL, c));
    str[size] = NULL;
    free(cp);
    return (str);
}

int free_array(char **str, int value)
{
    for (int i = 0; str[i] != NULL; ++i)
        free(str[i]);
    free(str);
    return (value);
}
