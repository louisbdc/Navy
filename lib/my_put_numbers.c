/*
** EPITECH PROJECT, 2021
** myprintf
** File description:
** my_put_numbers
*/

#include "my.h"

short my_put_short(short nb)
{
    if (nb >= 0 && nb < 10) {
        my_putchar(nb + 48);
    } else if (nb < 0) {
        my_putchar(45);
        my_put_short(-nb);
    } else {
        my_put_short(nb / 10);
        my_put_short(nb % 10);
    }
    return (0);
}

unsigned int my_put_unsigned(unsigned int nb)
{
    unsigned int max = 4294967295;

    if (nb >= 0 && nb < 10) {
        my_putchar(nb + 48);
    } else if (nb < 0) {
        my_put_unsigned((max - nb) / 10);
        my_put_unsigned((max - nb) % 10);
    } else {
        my_put_unsigned(nb / 10);
        my_put_unsigned(nb % 10);
    }
    return (0);
}

int my_put_nbr(int nb)
{
    if (nb >= 0 && nb < 10) {
        my_putchar(nb + 48);
    } else if (nb < 0) {
        my_putchar(45);
        my_put_nbr(-nb);
    } else {
        my_put_nbr(nb / 10);
        my_put_nbr(nb % 10);
    }
    return (0);
}

long my_put_long(long nb)
{
    if (nb >= 0 && nb < 10) {
        my_putchar(nb + 48);
    } else if (nb < 0) {
        my_putchar(45);
        my_put_long(-nb);
    } else {
        my_put_long(nb / 10);
        my_put_long(nb % 10);
    }
    return (0);
}