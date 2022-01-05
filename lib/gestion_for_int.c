/*
** EPITECH PROJECT, 2021
** my_printf
** File description:
** reproduce the printf fonction
*/

#include <stdarg.h>
#include "../includes/my.h"

void is_there_few_spaces(struct_t *var, char *type_to_print)
{
    int j = 1;

    while (type_to_print[var->i + var->after_modulo - j] == 'h' ||
    (type_to_print[var->i + var->after_modulo - j] >= '0' &&
    type_to_print[var->i + var->after_modulo - j] <= '9')){
        j++;
    }
    var->nbr_0_before = var->i + var->after_modulo - j;
    for (j = var->i + var->after_modulo - j + 1; j < var->i + var->after_modulo
    && type_to_print[j] != 'h'; j++) {
        var->nbr_0 = var->nbr_0 * 10 + type_to_print[j] - 48;
    }
    for (int i = var->nbr_0_before; type_to_print[i] != '%'; i--) {
        if (type_to_print[i] == '-') {
            var->nbr_0_before = var->nbr_0;
            var->nbr_0 = 0;
            break;
        } else
            var->nbr_0_before = 0;
    }
}

void is_there_a_space(struct_t *var, char *type_to_print)
{
    var->plus = 0;
    var->nbr_0 = 0;
    var->nbr_0_before = 0;
    var->space = 0;
    var->diez = 0;
    var->char0 = 0;
    for (int j = var->i; j < var->i + var->after_modulo; j++) {
        if (type_to_print[j] == '+')
            var->plus = 1;
        if (type_to_print[j] == '#')
            var->diez = 1;
        if (type_to_print[j] == '0' && var->nbr_0 == 0 &&
        var->nbr_0_before == 0)
            var->char0 = 1;
        if (type_to_print[j] >= '0' && type_to_print[j] <= '9' &&
        var->nbr_0 == 0 && var->nbr_0_before == 0)
            is_there_few_spaces(var, type_to_print);
    }
}

void gestion_2(struct_t *var, int len, int character, char *type_to_print)
{
    len++;
    character++;
    if (var->plus == 1)
        return;
    for (int i = 1; i <= var->after_modulo; i++) {
        if (type_to_print[i + var->i] == ' ') {
            my_putchar(' ');
            var->space = 1;
            break;
        }
    }
}

void gestion_for_int(va_list arg, struct_t *var,
char *type_to_print, long long nbr)
{
    int len = my_longlen(nbr), character = 0;

    is_there_a_space(var, type_to_print);
    if (type_to_print[var->i + var->after_modulo - 1] == '*')
        var->nbr_0 = va_arg(arg, int);
    character = var->nbr_0 + var->nbr_0_before - var->plus;
    gestion_2(var, len, character, type_to_print);
    if_space(var, character, len);
    if (var->plus == 1)
        my_putchar('+');
    if_0(var, character, len);
    my_put_nbr(nbr);
    if (character - var->space <= len)
        return;
    if (var->nbr_0_before != 0) {
        for (int i = 0; i < character - var->space - len; i++) {
            my_putchar(' ');
        }
    }
}

void gestion_for_char(struct_t *var, char *type_to_print, char nbr)
{
    int character;

    is_there_a_space(var, type_to_print);
    character = var->nbr_0 + var->nbr_0_before;
    if (var->nbr_0_before == 0)
        gestion_2(var, 1, character, type_to_print);
    if (var->nbr_0 != 0) {
        for (int i = 0; i < character - var->space - 1; i++) {
            my_putchar(' ');
        }
    }
    my_putchar(nbr);
    if (character - var->space <= 1)
        return;
    if (var->nbr_0_before != 0) {
        for (int i = 0; i < character - var->space - 1; i++) {
            my_putchar(' ');
        }
    }
}
