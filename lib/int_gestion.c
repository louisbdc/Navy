/*
** EPITECH PROJECT, 2021
** parantheses
** File description:
** take off parantheses
*/

#include "../includes/my.h"

int my_int_len(int nbr)
{
    int len = 0;

    if (nbr < 0)
        nbr = nbr * -1;
    if (nbr == 0)
        return 1;
    while (nbr != 0) {
        nbr = nbr / 10;
        len++;
    }
    return (len);
}

char *my_int_str(int nbr)
{
    int length = my_int_len(nbr);
    int i = 0;
    int pos = 0;
    char *strmalloc = malloc(sizeof(char) * (length + 2));

    if (nbr < 0) {
        nbr = nbr * -1;
        pos = -1;
    }
    for (; i < length; i++) {
        strmalloc[i] = nbr % 10 + 48;
        nbr = nbr / 10;
    }
    if (pos == -1) {
        strmalloc[i] = '-';
        strmalloc[i + 1] = '\0';
    } else
        strmalloc[i] = '\0';
    strmalloc = my_revstr(strmalloc);
    return (strmalloc);
}
