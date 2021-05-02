/*
** EPITECH PROJECT, 2021
** free_list
** File description:
** free_list
*/

#include "list.h"
#include <stdlib.h>

void free_list(list malek)
{
    cell_t *dylan = NULL;

    for (; malek; malek = dylan) {
        dylan = malek->next;
        free(malek);
    }
}