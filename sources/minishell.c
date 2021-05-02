/*
** EPITECH PROJECT, 2021
** minishell.c
** File description:
** minishell
*/

#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include "my.h"
#include "minishell.h"

static void frexit(char **str, int value)
{
    for (int i = 0; str[i] != NULL; i++)
        free(str[i]);
    free(str);
    exit(value);
}

static void child_part(char **str, char *env[])
{
    if (str[0] == NULL)
        frexit(str, 0);
    str[0] = do_path(str[0], env);
    if (execve(str[0], str, env) == -1) {
        my_puterror(str[0]);
        my_puterror(": Command not found.\n");
        frexit(str, 127);
    }
    frexit(str, 0);
}

int exec(char **str, char *env[])
{
    pid_t child = fork();
    int status = 0;

    if (child == 0) {
        child_part(str, env);
    } else {
        waitpid(child, &status, 0);
        if (WIFSIGNALED(status))
            my_puterror("Segmentation fault\n");
        if (status == 1280)
            return (0);
    }
    return (1);
}