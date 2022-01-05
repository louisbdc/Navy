/*
** EPITECH PROJECT, 2021
** my_printf
** File description:
** reproduce the printf fonction
*/

#include <stdarg.h>
#include "../includes/my.h"

void gestion_for_str(va_list arg, struct_t *var,
char *type_to_print, char *str)
{
    int len = my_strlen(str), character;
    int i = 0;

    if (type_to_print[var->i + var->after_modulo] == '*')
        i = va_arg(arg, int);
    is_there_a_space(var, type_to_print);
    character = var->nbr_0 + var->nbr_0_before + i;
    if (var->nbr_0 != 0) {
        for (int i = 0; i < character - len; i++) {
            my_putchar(' ');
        }
    }
    my_putstr(str);
    if (character <= len)
        return;
    if (var->nbr_0_before != 0) {
        for (int i = 0; i < character - len; i++) {
            my_putchar(' ');
        }
    }
}

void gestion_for_oct_str(struct_t *var, char *type_to_print, char *str)
{
    int len = my_strlen(str), character;

    is_there_a_space(var, type_to_print);
    character = var->nbr_0 + var->nbr_0_before;
    if (var->nbr_0 != 0) {
        for (int i = 0; i < character - len; i++) {
            my_putchar(' ');
        }
    }
    my_putstr_s(str);
    if (character <= len)
        return;
    if (var->nbr_0_before != 0) {
        for (int i = 0; i < character - len; i++) {
            my_putchar(' ');
        }
    }
}

void gestion_for_u(struct_t *var, char *type_to_print, unsigned int nbr)
{
    int len = my_longlen(nbr), character;

    is_there_a_space(var, type_to_print);
    character = var->nbr_0 + var->nbr_0_before;
    if (var->nbr_0 != 0) {
        for (int i = 0; i < character - len; i++) {
            my_putchar(' ');
        }
    }
    my_put_nbr(nbr);
    if (character <= len)
        return;
    if (var->nbr_0_before != 0) {
        for (int i = 0; i < character - len; i++) {
            my_putchar(' ');
        }
    }
}

void my_putstr_p(char *nbr)
{
    my_putchar('0');
    my_putchar('x');
    my_putstr(nbr);
}

void gestion_for_p(struct_t *var, char *type_to_print, char *nbr)
{
    int len = my_strlen(nbr) + 2, character = 0;

    is_there_a_space(var, type_to_print);
    character = var->nbr_0 + var->nbr_0_before - var->plus;
    gestion_2(var, len, character, type_to_print);
    if (var->nbr_0 != 0) {
        for (int i = 0; i < character - var->space - len; i++) {
            my_putchar(' ');
        }
    }
    if (var->plus == 1)
        my_putchar('+');
    my_putstr_p(nbr);
    if (character - var->space <= len)
        return;
    if (var->nbr_0_before != 0) {
        for (int i = 0; i < character - var->space - len; i++) {
            my_putchar(' ');
        }
    }
}
