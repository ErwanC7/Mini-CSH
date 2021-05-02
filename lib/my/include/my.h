/*
** EPITECH PROJECT, 2021
** include
** File description:
** include
*/

#ifndef _MY_H_
#define _MY_H_

char *my_concat(char const *cat, char const *str, char c);
void my_putstr(char const *str);
void my_puterror(char const *str);
int my_strcmp(char const *str, char const *cmp);
int my_strncmp(char const *str, char const *cmp, unsigned int n);
unsigned int my_strlen(char const *str);
char *my_strdup(char const *str);
char *clean_str(char *str);
char **str_to_word_array(char *buffer, char const *c);
int free_array(char **str, int value);

#endif /* _MY_H_ */
