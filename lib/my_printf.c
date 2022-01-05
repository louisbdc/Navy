/*
** EPITECH PROJECT, 2021
** my_printf
** File description:
** reproduce the printf fonction
*/

#include <stdarg.h>
#include "../includes/my.h"

int if_h(struct_t *var, char *type_to_print)
{
    if (type_to_print[var->i] == '%' && type_to_print[var->i + 1] == 'h' &&
    type_to_print[var->i + 2] == 'h')
        return (2);
    if (type_to_print[var->i] == '%' && type_to_print[var->i + 1] == 'h')
        return (1);
    return (0);
}

int to_return(char const *type_to_print, int i)
{
    for (; type_to_print[i] >= '0' && type_to_print[i] <= '9'; i++) {
    }
    if (type_to_print[i] == 'h' && type_to_print[i + 1] == 'h' &&
    type_to_print[i + 2] != 'h')
        return (i + 2);
    if (type_to_print[i] == 'h' && type_to_print[i + 1] != 'h')
        return (i + 1);
    return (i);
}

int number_or_h(char const *type_to_print, int i)
{
    if (type_to_print[i] >= '0' && type_to_print[i] <= '9')
        return (to_return(type_to_print, i));
    if (type_to_print[i] == 'h' && type_to_print[i + 1] == 'h' &&
    type_to_print[i + 2] != 'h')
        return (i + 2);
    if (type_to_print[i] == 'h' && type_to_print[i + 1] != 'h')
        return (i + 1);
    return (i);
}

int next_char(char const *type_to_print)
{
    for (int i = 0; i < my_strlen(type_to_print); i++) {
        if (type_to_print[i] == ' ' || type_to_print[i] == '-' ||
        type_to_print[i] == '+' || type_to_print[i] == '0' ||
        type_to_print[i] == '#' || type_to_print[i] == '*') {
            continue;
        } else
            return (number_or_h(type_to_print, i) + 1);
    }
    return (1);
}

void my_printf(char *type_to_print, ...)
{
    va_list arguments;
    struct_t *var = malloc(sizeof(struct_t));

    va_start(arguments, type_to_print);
    for (var->i = 0; var->i < my_strlen(type_to_print); var->i++) {
        if (type_to_print[var->i] == '%' && (my_printf_2(var, arguments,
        type_to_print) == 0 || my_printf_3(var, arguments, type_to_print) ==
        0 || my_printf_4(var, arguments, type_to_print) == 0 ||
        my_printf_5(var, arguments, type_to_print) == 0 ||
        my_printf_6(var, arguments, type_to_print) == 0 ||
        my_printf_7(var, arguments, type_to_print) == 0))
            continue;
        else {
            my_putchar(type_to_print[var->i]);
            var->i += if_h(var, type_to_print);
        }
    }
    va_end(arguments);
}
