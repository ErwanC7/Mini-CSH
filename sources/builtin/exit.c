/*
** EPITECH PROJECT, 2021
** exit
** File description:
** exit
*/

#include <stdlib.h>
#include "list.h"

void exit_shell(char **str, list env)
{
    for (int i = 0; str[i] != NULL; ++i)
        free(str[i]);
    free(str);
    free_list(env);
    exit(0);
}