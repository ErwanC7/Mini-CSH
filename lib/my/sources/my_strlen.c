/*
** EPITECH PROJECT, 2021
** my_strlen
** File description:
** get length of a string
*/

unsigned int my_strlen(char const *str)
{
    unsigned int i = 0;

    for (; str[i] != '\0'; ++i);
    return (i);
}