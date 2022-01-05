/*
** EPITECH PROJECT, 2021
** _h.c
** File description:
** Created by louis on 09/12/2021.
*/

#include "my.h"

int dash_h(char *file)
{
    char *buffer;
    int fd = open(file, O_RDONLY);
    buffer = malloc(sizeof(char) * (200 + 1));
    read(fd, buffer, 200);
    buffer[200] = '\0';
    write(1, buffer, 200);
    my_putchar('\n');
    free(buffer);
    return 0;
}
