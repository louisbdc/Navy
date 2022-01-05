/*
** EPITECH PROJECT, 2021
** my_printf
** File description:
** reproduce the printf fonction
*/

#include <stdarg.h>
#include "../includes/my.h"

void add_0(char *nbr)
{
    int len = my_strlen(nbr);

    for (int i = len; i < 3; i++) {
        my_putchar('0');
    }
    my_putstr(nbr);
}

int my_putstr_s(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] >= 127 || str[i] <= 31) {
            my_putchar('\\');
            add_0(base(str[i], "01234567"));
        } else
            my_putchar(str[i]);
        i++;
    }
    return (0);
}

int my_printf_6(struct_t *var, va_list arguments, char *type_to_print)
{
    char *stock;

    if (type_to_print[var->i + var->after_modulo] == 'S') {
        gestion_for_oct_str(var, type_to_print, va_arg(arguments, char *));
        var->i += var->after_modulo;
        return (0);
    }
    if (type_to_print[var->i + var->after_modulo] == 'p') {
        stock = my_strdup(base(va_arg(arguments, int), "0123456789abcdef"));
        gestion_for_p(var, type_to_print, stock);
        var->i += var->after_modulo;
        free(stock);
        return (0);
    }
    return (1);
}
