/*
** EPITECH PROJECT, 2021
** my_strdup.c
** File description:
** dupe
*/

#include <stdio.h>
#include <stdlib.h>
#include "my.h"

char *my_strcpy(char *dest, const char *src);

char *my_strdup(char const *src)
{
    int index = my_strlen(src);
    char *new = malloc(sizeof(char) * (index + 1));

    my_strcpy(new, src);
    return new;
}
