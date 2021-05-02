/*
** EPITECH PROJECT, 2021
** get_command
** File description:
** get_command
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "my.h"
#include "minishell.h"

char **get_cmd(void)
{
    char **str;
    char *line = NULL;
    size_t len = 0;
    ssize_t linesize = getline(&line, &len, stdin);

    if (linesize == -1) {
        free(line);
        if (isatty(0) == 1)
            my_putstr("exit\n");
        return (NULL);
    }
    if (line[linesize - 1] == '\n')
        line[linesize - 1] = '\0';
    clean_str(line);
    str = str_to_word_array(line, ";");
    free(line);
    return (str);
}
