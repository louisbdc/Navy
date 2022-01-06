/*
** EPITECH PROJECT, 2021
** bsq
** File description:
** str_to_int
*/

#include"my.h"

int str_to_int(char *str)
{
    int a = 0;

    for (int i = 0; i != my_strlen(str); i++)
        a = ((str[i] - 48) + a) * 10;
        a = a / 10;
    return a;
}

char *my_itoa(int a)
{
    char *str;
    int i = 0;

    str = malloc(sizeof(char) * 11);
    if (a < 10)
        str[i]= ('0' + a);
    else
            str[i] = ('0' + (a % 10));
            str[i + 1] = ('0' + a / 10);
            str = my_revstr(str);
    return str;
}