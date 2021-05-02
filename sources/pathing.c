/*
** EPITECH PROJECT, 2021
** pathing
** File description:
** pathing
*/

#include <stdlib.h>
#include <unistd.h>
#include "my.h"
#include "minishell.h"

static char *get_path(char const *str)
{
    char *new;
    int i = 0;

    new = malloc(sizeof(char) * (my_strlen(str) - 4));
    for (i = 5; str[i] != '\0'; ++i)
        new[i - 5] = str[i];
    new[i - 5] = '\0';
    return (new);
}

static char **found_path(char * const env[])
{
    char *new;
    char **path = {NULL};

    for (int i = 0; env[i] != NULL; ++i) {
        if (my_strncmp(env[i], "PATH=", 5) == 0) {
            new = get_path(env[i]);
            path = str_to_word_array(new, ":");
            free(new);
            break;
        }
    }
    return (path);
}

static void free_path(char **path)
{
    for (int i = 0; path[i] != NULL; ++i)
        free(path[i]);
    free(path);
}

char *do_path(char *str, char * const env[])
{
    char **path = found_path(env);
    char *all;

    for (int j = 0; path[j] != NULL; j++) {
        all = my_concat(path[j], str, '/');
        if (access(all, X_OK) == 0) {
            free(str);
            free_path(path);
            return (all);
        }
        free(all);
    }
    free_path(path);
    return (str);
}