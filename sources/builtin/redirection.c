/*
** EPITECH PROJECT, 2021
** redirection
** File description:
** redirection
*/

#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <sys/wait.h>
#include "my.h"
#include "minishell.h"

static void child_part(char **str, list env, int fd, int i)
{
    int h = 0;

    if (dup2(fd, 1) == -1) {
        my_puterror(strerror(errno));
        my_puterror("\n");
        return;
    }
    clean_str(str[0]);
    for (i = 1; str[i][0] != '>'; ++i);
    str[i] = NULL;
    for (h = 0; h < builtin_size; ++h) {
        if (my_strcmp(str[0], commands[h].string) == 0) {
            commands[h].ptr(str, env);
            exit(0);
        }
    }
    if (h == builtin_size && !exec(str, list_to_array(env)))
        exit(0);
    exit(0);
}

void redirection(char **str, list env)
{
    int fd;
    int i = 0;
    int status = 0;
    pid_t child = 0;

    for (i = 1; str[i] != NULL && str[i][0] != '>'; ++i);
    if (str[i] == NULL || str[i + 1] == NULL)
        return my_puterror("Missing name for redirect.\n");
    if (str[i][1] == '>')
        fd = open(str[i + 1], O_APPEND | O_CREAT | O_WRONLY, 0664);
    else
        fd = open(str[i + 1], O_CREAT | O_TRUNC | O_WRONLY, 0664);
    child = fork();
    if (child == 0) {
        child_part(str, env, fd, i);
    } else {
        wait(&status);
        if (WIFSIGNALED(status))
            my_puterror("Segmentation fault\n");
    }
}