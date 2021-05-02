/*
** EPITECH PROJECT, 2021
** change_directory
** File description:
** change_directory
*/

#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <limits.h>
#include "my.h"
#include "minishell.h"

static void error_msg(char const *arg)
{
    my_puterror(arg);
    my_puterror(": ");
    my_puterror(strerror(errno));
    my_puterror(".\n");
}

static int find_in_env(char *str, list env)
{
    int i = 0;
    char **path;

    if ((i = str_in_env(str, env))) {
        for (int j = 0; j < i; ++j, env = env->next);
        path = str_to_word_array(env->str, "=");
        chdir(path[1]);
        free_array(path, 0);
        return (1);
    }
    return (0);
}

void change_directory(char **str, list env)
{
    char pwd[PATH_MAX];

    getcwd(pwd, sizeof(pwd));
    if (str[1] == NULL) {
        set_env((char *[]){"setenv", "OLDPWD", pwd, NULL}, env);
        if (!find_in_env("HOME=", env))
            my_puterror("cd: No home directory.\n");
        return;
    }
    if (str[2] != NULL)
        return my_puterror("cd: too many arguments.\n");
    if (str[1][0] == '-' && str[1][1] == '\0') {
        if (!find_in_env("OLDPWD=", env))
            my_puterror(": No such file or directory.\n");
        return;
    }
    if (chdir(str[1]) == -1)
        error_msg(str[1]);
    else
        set_env((char *[]){"setenv", "OLDPWD", pwd, NULL}, env);
}