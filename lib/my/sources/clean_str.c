/*
** EPITECH PROJECT, 2021
** clean_str
** File description:
** clean a string from too much space/tab
*/

char *clean_str(char *str)
{
    int i = 0;
    int j = 0;

    for (; str[j] == ' ' || str[j] == '\t'; ++j);
    str[i] = str[j];
    for (int k = 0; str[i] != '\0' && str[j] != '\0'; ++i, ++j) {
        for (k = 0; str[j] == ' ' || str[j] == '\t'; ++j, k = 1);
        if ((str[j] == '\0' && str[j - 1] == ' ') ||
                (str[j + 1] == '\0' && str[j] == ' '))
            break;
        else if (k > 0)
            str[i++] = ' ';
        str[i] = str[j];
    }
    for (; str[i] != '\0'; ++i)
        str[i] = '\0';
    return (str);
}