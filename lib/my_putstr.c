/*
** EPITECH PROJECT, 2021
** my_putstr.c
** File description:
** none
*/

#include "my.h"

int my_putstr(char const *str)
{
    int i = 0;
    while (str[i] != '\0') {
        my_putchar(str[i]);
        i += 1;
    }
    return 0;
}
