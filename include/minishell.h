/*
** EPITECH PROJECT, 2021
** minishell.h
** File description:
** header of minishell
*/

#ifndef _MINISHELL2_H_
#define _MINISHELL2_H_

#include "list.h"

typedef struct builtin_s {
    char *string;
    void (*ptr)(char **, list);
}builtin_t;

/*       exec       */
char **get_cmd(void);
char *do_path(char *str, char * const env[]);
int exec(char **str, char *env[]);

/*       builtin       */
void exit_shell(char **str, list env);
void change_directory(char **str, list env);
void set_env(char **str, list env);
void unset_env(char **str, list env);
void print_env(char **str, list env);
void redirection(char **str, list env);

/*       env       */
list create_env(char *str[]);
char **list_to_array(list env);
int str_in_env(char *str, list env);

/*       array of commands       */
static const builtin_t commands[] = {
        {.string = "exit", exit_shell},
        {.string = "cd", change_directory},
        {.string = "setenv", set_env},
        {.string = "env", print_env},
        {.string = "unsetenv", unset_env},
};

static const int builtin_size = sizeof(commands) / sizeof(commands[0]);

#endif /* _MINISHELL2_H_ */
