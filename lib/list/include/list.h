/*
** EPITECH PROJECT, 2021
** list.h
** File description:
** header of list
*/

#ifndef _LIST_H_
#define _LIST_H_

typedef struct cell_s {
    char *str;
    struct cell_s *next;
}cell_t, *list;

int list_len(list malek);
list del(list malek, int pos);
list add(list malek, char *adding);
void free_list(list malek);

#endif /* _LIST_H_ */