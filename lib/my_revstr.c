/*
** EPITECH PROJECT, 2021
** rev_str.c
** File description:
** try
*/

#include "my.h"

char *my_revstr(char *str)
{
    char buf;
    int i = 0;
    int index = my_strlen(str) - 1;

    while (index >= 0 && i <= (index / 2)) {
        buf = str[i];
        str[i] = str[index - i];
        str[index - i] = buf;
        i++;
    }
    return str;
}
