/*
** EPITECH PROJECT, 2021
** env
** File description:
** env
*/

#include <stdlib.h>
#include "my.h"
#include "minishell.h"

void print_env(char **str, list env)
{
    (void)str;
    for (; env != NULL; env = env->next) {
        my_putstr(env->str);
        my_putstr("\n");
    }
}

void set_env(char **str, list env)
{
    (void)str;
    char *path;

    if (str[1] == NULL)
        return print_env(str, env);
    if (str[2] == NULL) {
        path = my_concat(str[1], "", '=');
        add(env, path);
    } else if (str[3] == NULL) {
        path = my_concat(str[1], "=", '\0');
        if (str_in_env(path, env))
            del(env, str_in_env(path, env));
        free(path);
        path = my_concat(str[1], str[2], '=');
        add(env, path);
    } else {
        my_puterror("setenv: Too many arguments.\n");
    }
}

void unset_env(char **str, list env)
{
    if (str[1] == NULL)
        return my_puterror("unsetenv: Too few arguments.\n");
    for (int i = 1, pos = 0; str[i] != NULL; ++i) {
        pos = str_in_env(str[i], env);
        if (pos != 0)
            del(env, pos);
    }
}
