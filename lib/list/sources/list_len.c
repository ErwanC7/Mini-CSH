/*
** EPITECH PROJECT, 2021
** list_len
** File description:
** list_len
*/

#include <stdlib.h>
#include "list.h"

int list_len(list malek)
{
    int i = 0;

    if (malek == NULL)
        return (i);
    for (;malek->next != NULL; i += 1)
        malek = malek->next;
    return (i);
}