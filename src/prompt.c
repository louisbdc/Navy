/*
** EPITECH PROJECT, 2021
** prompt.c
** File description:
** Created by louis on 09/12/2021.
*/

#include "my.h"

char *prompt()
{
    size_t bufsize = 32;
    char *buffer = malloc(sizeof(char) * bufsize);
    if (buffer == NULL)
        return NULL;
    my_putstr("attack: ");
    getline(&buffer, &bufsize, stdin);
    return buffer;
}
