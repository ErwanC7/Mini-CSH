/*
** EPITECH PROJECT, 2021
** environment
** File description:
** environment
*/

#include <stdlib.h>
#include "my.h"
#include "list.h"

list create_env(char *str[])
{
    list env = NULL;

    for (int i = 0; str[i] != NULL; ++i)
        env = add(env, str[i]);
    return (env);
}

char **list_to_array(list env)
{
    int size = list_len(env);
    char **str = malloc(sizeof(char *) * (size + 1));

    for (int i = 0; env != NULL ; env = env->next, ++i)
        str[i] = env->str;
    str[size] = NULL;
    return (str);
}

int str_in_env(char *str, list env)
{
    int i = 0;

    for (list temp = env; temp != NULL; temp = temp->next, ++i) {
        if (my_strncmp(temp->str, str, my_strlen(str)) == 0)
            return (i);
    }
    return (0);
}