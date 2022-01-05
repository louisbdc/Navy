/*
** EPITECH PROJECT, 2021
** my_printf
** File description:
** reproduce the printf fonction
*/

#include <stdarg.h>
#include "../includes/my.h"

void wich_character(struct_t *var)
{
    if (var->char0 == 1) {
        my_putchar('0');
    } else
        my_putchar(' ');
}

void gestion_for_oct(struct_t *var, char *type_to_print, char *str)
{
    int len = my_strlen(str), character;

    is_there_a_space(var, type_to_print);
    character = var->nbr_0 + var->nbr_0_before - var->diez;
    if (var->nbr_0 != 0) {
        for (int i = 0; i < character - len; i++) {
            wich_character(var);
        }
    }
    if (var->diez == 1)
        my_putchar('0');
    my_putstr(str);
    if (character <= len)
        return;
    if (var->nbr_0_before != 0) {
        for (int i = 0; i < character - len; i++) {
            my_putchar(' ');
        }
    }
}

void for_bases(struct_t *var)
{
    if (var->diez == 1)
        var->diez = 2;
}

void gestion_for_x(struct_t *var, char *type_to_print, char *str)
{
    int len = my_strlen(str), character;

    is_there_a_space(var, type_to_print);
    for_bases(var);
    character = var->nbr_0 + var->nbr_0_before - var->diez;
    if (var->nbr_0 != 0) {
        for (int i = 0; i < character - len; i++) {
            wich_character(var);
        }
    }
    if (var->diez == 2)
        my_putstr("0x\0");
    my_putstr(str);
    if (character <= len)
        return;
    if (var->nbr_0_before != 0) {
        for (int i = 0; i < character - len; i++) {
            my_putchar(' ');
        }
    }
}

void gestion_for_big_x(struct_t *var, char *type_to_print, char *str)
{
    int len = my_strlen(str), character;

    is_there_a_space(var, type_to_print);
    for_bases(var);
    character = var->nbr_0 + var->nbr_0_before - var->diez;
    if (var->nbr_0 != 0) {
        for (int i = 0; i < character - len; i++) {
            wich_character(var);
        }
    }
    if (var->diez == 2)
        my_putstr("0x\0");
    my_putstr(str);
    if (character <= len)
        return;
    if (var->nbr_0_before != 0) {
        for (int i = 0; i < character - len; i++) {
            my_putchar(' ');
        }
    }
}
