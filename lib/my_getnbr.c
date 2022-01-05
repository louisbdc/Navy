/*
** EPITECH PROJECT, 2021
** getnbr
** File description:
** change a str to a nbr
*/

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "my.h"

int pwt(int a)
{
    int n;

    n = 1;
    while (a > 0) {
        n = n * 10;
        a = a - 1;
    }
    return n;
}

int my_strl(char *str)
{
    int i;
    char iot;
    i = 0;
    iot = *str;
    while (iot == '-' || iot == '+') {
        i = i + 1;
        iot = *(str + i);
    }
    while (iot > 47 && iot < 58) {
        i = i + 1;
        iot = *(str + i);
    }

    return (i);
}

char *my_evil_nbr(char *nbr)
{
    int i;
    int nb;
    char c;

    nb = my_strl(nbr) - 1;
    i = nb;

    while (nb > i / 2) {
        c = *(nbr + nb);
        *(nbr + nb) = *(nbr + (i - nb));
        *(nbr + (i - nb)) = c;
        nb = nb - 1;
    }
    return (nbr);
}

int my_getnbr(char *str)
{
    int i;
    int neg;
    long nb;
    int nb_digits;
    i = my_strl(str);
    neg = 0;
    str = my_evil_nbr(str);
    nb = 0;
    nb_digits = 0;
    while (i > 0) {
        i = i - 1;
        if (*(str + i) > 47 && *(str + i) < 58) {
            nb = nb + (*(str + i) - 48) * pwt(i);
            nb_digits = nb_digits + 1;
        } else if (*(str + i) == '-')
            neg = !neg;
    }
    if ((nb > 2147483647 && !neg)
    || (nb > 2147483648  && neg) || nb_digits > 11)
        nb = 0;
    return ((neg) ? -nb : nb);
}
