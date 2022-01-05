/*
** EPITECH PROJECT, 2021
** my_strsdup
** File description:
** copies a string from a up to b
*/

#include <stdlib.h>

char *my_strsdup(const char *str, int b, int l)
{
    int i = 0;
    int end = b + l;
    char *dest = malloc(sizeof(char) * (l + 1));

    for (; str[b] != str[end]; b++) {
        dest[i] = str[b];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}

char *my_strduptoend(char *str, int beg)
{
    int index = 0;
    int j = 0;

    for (int i = beg; str[i] != '\0'; i++)
        index++;
    char *dest = malloc(sizeof(char) * (index + 1));
    for (int i = beg; str[i] != '\0'; i++) {
        dest[j] = str[i];
        j++;
    }
    dest[j] = '\0';
    return (dest);
}