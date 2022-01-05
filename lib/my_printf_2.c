/*
** EPITECH PROJECT, 2021
** my_printf
** File description:
** reproduce the printf fonction
*/

#include <stdarg.h>
#include "../includes/my.h"

int my_printf_2(struct_t *var, va_list arguments, char *type_to_print)
{
    char *stock;

    var->after_modulo = next_char(&type_to_print[var->i + 1]);
    if (type_to_print[var->i + var->after_modulo] == '%') {
        my_putchar('%');
        var->i += var->after_modulo;
        return (0);
    }
    if (type_to_print[var->i + var->after_modulo] == '\0')
        return (0);
    if (type_to_print[var->i + var->after_modulo] == 'b') {
        stock = my_strdup(base(va_arg(arguments, int), "01"));
        gestion_for_oct(var, type_to_print, stock);
        var->i += var->after_modulo;
        free(stock);
        return (0);
    }
    return (1);
}

int my_printf_3(struct_t *var, va_list arguments, char *type_to_print)
{
    if (type_to_print[var->i + var->after_modulo] == 'i' ||
    type_to_print[var->i + var->after_modulo] == 'd') {
        gestion_for_int(arguments, var, type_to_print, va_arg(arguments, int));
        var->i += var->after_modulo;
        return (0);
    }
    if (type_to_print[var->i + var->after_modulo] == 'u') {
        gestion_for_u(var, type_to_print, va_arg(arguments, unsigned int));
        var->i += var->after_modulo;
        return (0);
    }
    if (type_to_print[var->i + var->after_modulo] == 'c') {
        gestion_for_char(var, type_to_print, va_arg(arguments, int));
        var->i += var->after_modulo;
        return (0);
    }
    return (1);
}

int my_printf_4(struct_t *var, va_list arg, char *type_to_print)
{
    char *stock;

    if (type_to_print[var->i + var->after_modulo] == 's') {
        gestion_for_str(arg, var, type_to_print, va_arg(arg, char *));
        var->i += var->after_modulo;
        return (0);
    }
    if (type_to_print[var->i + var->after_modulo] == 'x') {
        stock = my_strdup(base(va_arg(arg, int), "0123456789abcdef"));
        gestion_for_x(var, type_to_print, stock);
        var->i += var->after_modulo;
        return (0);
    }
    if (type_to_print[var->i + var->after_modulo] == 'X') {
        stock = my_strdup(base(va_arg(arg, int), "0123456789ABCDEF"));
        gestion_for_big_x(var, type_to_print, stock);
        var->i += var->after_modulo;
        return (0);
    }
    return (1);
}

int my_printf_5(struct_t *var, va_list arg, char *type_to_print)
{
    char *stock;

    if ((type_to_print[var->i + var->after_modulo] == 'l' &&
    type_to_print[var->i + var->after_modulo + 1] == 'd') ||
    (type_to_print[var->i + var->after_modulo] == 'l' &&
    type_to_print[var->i + var->after_modulo + 1] == 'i')) {
        gestion_for_int(arg, var, type_to_print, va_arg(arg, long long));
        var->i += var->after_modulo + 1;
        return (0);
    }
    if (type_to_print[var->i + var->after_modulo] == 'o') {
        stock = my_strdup(base(va_arg(arg, int), "01234567"));
        gestion_for_oct(var, type_to_print, stock);
        var->i += var->after_modulo;
        free(stock);
        return (0);
    }
    return (1);
}

int my_printf_7(struct_t *var, va_list arguments, char *type_to_print)
{
    if (type_to_print[var->i + var->after_modulo] == 't') {
        my_show_array(va_arg(arguments, char **));
        var->i += var->after_modulo;
        return (0);
    }
    return (1);
}
