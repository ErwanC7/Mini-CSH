/*
** EPITECH PROJECT, 2021
** add
** File description:
** add
*/

#include <stdlib.h>
#include "list.h"

static cell_t *create_cell(char *adding)
{
    cell_t *cells = malloc(sizeof(cell_t));

    cells->str = adding;
    cells->next = NULL;
    return (cells);
}

list add(list malek, char *adding)
{
    cell_t *cells = create_cell(adding);
    cell_t *temp = malek;
    cell_t *save = malek;

    if (temp == NULL)
        return (cells);
    for (int i = 0; temp != NULL; i++) {
        save = temp;
        temp = temp->next;
    }
    save->next = cells;
    cells->next = temp;
    return (malek);
}