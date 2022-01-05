/*
** EPITECH PROJECT, 2021
** my_show_array
** File description:
** show an array
*/

#include "../includes/my.h"

void my_show_array(char **tab)
{
    int i = 0;

    while (tab[i] != NULL) {
        write(1, tab[i], my_strlen(tab[i]));
        write(1, "\n", 1);
        i++;
    }
}
