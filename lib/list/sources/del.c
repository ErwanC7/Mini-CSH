/*
** EPITECH PROJECT, 2021
** add
** File description:
** add
*/

#include <stdlib.h>
#include "../include/list.h"

static list pos_o(list malek, list temp)
{
    temp = malek->next;
    free(malek);
    return (temp);
}

list del(list malek, int pos)
{
    cell_t *temp = malek;
    cell_t *save = malek;

    if (temp == NULL)
        return (NULL);
    if (pos == 0)
        return (pos_o(malek, temp));
    for (int i = 0, size = list_len(malek); i < pos && i < size; i++) {
        save = temp;
        temp = temp->next;
    }
    save->next = temp->next;
    free(temp);
    return (malek);
}
