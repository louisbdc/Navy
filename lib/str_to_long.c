/*
** EPITECH PROJECT, 2021
** bsq
** File description:
** str_to_long
*/

#include "my.h"

long str_to_long(char *str)
{
    long a = 0;

    for (long i = 0; i != my_strlen(str); i++)
        a = ((str[i] - 48) + a) * 10;
    a = a / 10;
    return a;
}