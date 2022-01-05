/*
** EPITECH PROJECT, 2021
** my_put_nbr
** File description:
** affiche un nombre mis en entrée
*/
#include <stdio.h>
#include <unistd.h>

int my_longlen(long long nbr)
{
    int len = 0;

    while (nbr != 0) {
        nbr = nbr / 10;
        len++;
    }
    return (len);
}
