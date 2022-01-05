/*
** EPITECH PROJECT, 2021
** my_printf
** File description:
** reproduce the printf fonction
*/

#include <stdarg.h>
#include "../includes/my.h"

void if_space(struct_t *var, int character, int len)
{
    if (var->nbr_0 != 0 && var->char0 != 1) {
        for (int i = 0; i < character - var->space - len; i++) {
            my_putchar(' ');
        }
    }
}

void if_0(struct_t *var, int character, int len)
{
    if (var->nbr_0 != 0 && var->char0 == 1) {
        for (int i = 0; i < character - var->space - len; i++) {
            my_putchar('0');
        }
    }
}
