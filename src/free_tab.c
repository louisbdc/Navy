/*
** EPITECH PROJECT, 2021
** free_tab.c
** File description:
** Created by louis on 14/12/2021.
*/

#include "my.h"

void free_tab(char **tab)
{
    int i = 0;
    while (tab[i] != NULL) {
        free(tab[i]);
        i++;
    }
    free(tab);
}