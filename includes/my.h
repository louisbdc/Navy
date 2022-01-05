/*
** EPITECH PROJECT, 2021
** my.h
** File description:
** none
*/

#ifndef _MY_H
    #define _MY_H

    #include <unistd.h>
    #include <stdlib.h>
    #include <fcntl.h>
    #include <stdio.h>
    #include <stddef.h>
    #include <signal.h>
    #include <sys/sysinfo.h>
    #include <bits/sigaction.h>
    #include "struct.h"

    #define SIZE 512

void my_putchar(char c);
int my_atoi(char const *str);
int my_strlen(char const *str);
char *int_to_char(int result);
int my_putstr(char const *str);
void my_putchar(char c);
int my_putstr(char const *str);
int my_strlen(char const *str);
int my_put_nbr(long long long_nbr);
int my_int_len(int nbr);
char *my_revstr(char *str);
char *my_int_str(int nbr);
int my_longlen(long long nbr);
char *my_strdup(char const *src);
char *my_strcpy(char *dest, char const *src);
void my_show_array(char **tab);
char *my_strdupcat(char *dest, char const *src);
char *my_strlowcase(char *str);
int my_strcmp(char const *s1, char const *s2);
char *my_strcat(char *dest, char const *src);

//Bases fcts
char *base(long long nbr, char *convert_into);

//My_printf fcts
int next_char(char const *type_to_print);
int my_putstr_s(char const *str);
void is_there_a_space(struct_t *var, char *type_to_print);
void is_there_few_spaces(struct_t *var, char *type_to_print);
void wich_character(struct_t *var);
void if_0(struct_t *var, int character, int len);
void if_space(struct_t *var, int character, int len);
void gestion_2(struct_t *var, int len, int character, char *type_to_print);
void gestion_for_int(va_list arg, struct_t *var,
char *type_to_print, long long nbr);
void gestion_for_char(struct_t *var, char *type_to_print, char nbr);
void gestion_for_oct_str(struct_t *var, char *type_to_print, char *str);
void gestion_for_str(va_list arg, struct_t *var,
char *type_to_print, char *str);
void gestion_for_u(struct_t *var, char *type_to_print, unsigned int nbr);
void gestion_for_p(struct_t *var, char *type_to_print, char *nbr);
void gestion_for_oct(struct_t *var, char *type_to_print, char *str);
void gestion_for_x(struct_t *var, char *type_to_print, char *str);
void gestion_for_big_x(struct_t *var, char *type_to_print, char *str);
int my_printf_2(struct_t *var, va_list arguments, char *type_to_print);
int my_printf_3(struct_t *var, va_list arguments, char *type_to_print);
int my_printf_4(struct_t *var, va_list arguments, char *type_to_print);
int my_printf_5(struct_t *var, va_list arguments, char *type_to_print);
int my_printf_6(struct_t *var, va_list arguments, char *type_to_print);
int my_printf_7(struct_t *var, va_list arguments, char *type_to_print);
void my_printf(char *type_to_print, ...);

#endif
