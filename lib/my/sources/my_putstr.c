/*
** EPITECH PROJECT, 2021
** my_putstr
** File description:
** display string
*/

#include <unistd.h>

void my_putstr(char const *str)
{
    size_t i = 0;

    for (; str[i] != '\0'; ++i);
    write(1, str, i);
}

void my_puterror(char const *str)
{
    size_t i = 0;

    for (; str[i] != '\0'; ++i);
    write(2, str, i);
}