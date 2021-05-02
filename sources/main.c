/*
** EPITECH PROJECT, 2021
** main
** File description:
** main
*/

#include <unistd.h>
#include "my.h"
#include "minishell.h"

int display_help(void)
{
    my_putstr("USAGE\n"
            "    ./mysh\n\n"
            "DESCRIPITION\n"
            "    This is a short version of csh\n");
    return (0);
}

static int search_builtin(char **path, list env)
{
    int h = 0;

    for (h = 0; h < builtin_size; ++h) {
        if (my_strcmp(path[0], commands[h].string) == 0) {
            commands[h].ptr(path, env);
            break;
        }
    }
    return (h);
}

static int new_status(char **str, list env)
{
    int i = 0;
    char **path;

    for (int h = 0, a = 0; str[a] != NULL; ++a) {
        clean_str(str[a]);
        if (str[a][0] == '\0')
            continue;
        path = str_to_word_array(str[a], " ");
        for (i = 0; path[i] != NULL && path[i][0] != '>'; ++i);
        if (path[i] != NULL && path[i][0] == '>') {
            if (i == 0) {
                my_puterror("Missing name for redirect.\n");
                return (1);
            }
            redirection(path, env);
            continue;
        }
        h = search_builtin(path, env);
        if (h == builtin_size && !exec(path, list_to_array(env)))
            return (0);
        free_array(path, 0);
    }
    return (1);
}

void start(list env)
{
    char **str;

    for (int status = 1; status;) {
        if (isatty(0) == 1)
            my_putstr("$> ");
        if ((str = get_cmd()) == NULL)
            break;
        if (str[0][0] == '\0')
            continue;
        status = new_status(str, env);
        free_array(str, 0);
    }
}

int main(int ac, char const * const av[], char *env[])
{
    list environment;

    if (ac > 2 || env[0] == NULL)
        return (84);
    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h')
        return (display_help());
    environment = create_env(env);
    start(environment);
    free_list(environment);
    return (0);
}