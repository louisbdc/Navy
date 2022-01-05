/*
** EPITECH PROJECT, 2021
** all_boat_hit.c
** File description:
** Created by louis on 30/12/2021.
*/

#include "my.h"

int is_the_end(all_t *s_all, int nb, int usr)
{
    if (nb == 0) {
        my_printf("waiting for enemy's attack...\n");
        return (1);
    }
    s_all->nb_hit_boat += 1;
    if (s_all->nb_hit_boat == 14) {
        my_printf("I won\n");
        if (usr == 1)
            kill(s_all->usr2, SIGUSR1);
        if (usr == 2)
            kill(s_all->usr1, SIGUSR2);
        return 2;
    }
    my_printf("waiting for enemy's attack...\n");
    return 0;
}
