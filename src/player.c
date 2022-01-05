/*
** EPITECH PROJECT, 2021
** navy.c
** File description:
** Created by louis on 08/12/2021.
*/

#include "my.h"
extern int global;

int check_attack(all_t *s_all, char *file, char *file_2, int usr)
{
    char *coor;
    int touch;

    previous_attack();
    my_maps(file, file_2);
    coor = prompt();
    while (my_strlen(coor) != 3 || coor[0] < 'A' || coor[0] > 'H' ||
    coor[1] < '1' || coor[1] > '8' || check_coor(file, coor) == 1) {
        my_printf("wrong position\n");
        coor = prompt();
    }
    touch = write_file(file, file_2, coor);
    free(coor);
    return (is_the_end(s_all, touch, usr));
}

void player_one(all_t *s_all)
{
    struct sigaction sig;

    sig.sa_handler = signal_handler;
    while (global != SIGUSR2) {
        global = 0;
        if (check_attack(s_all, "map_usr_2_1.txt", "map_usr_1.txt", 1) == 2)
            return;
        kill(s_all->usr2, SIGUSR2);
        while (global != SIGUSR2 && global != SIGUSR1) {
            usleep(100000);
            sigaction(SIGUSR1, &sig, NULL);
            sigaction(SIGUSR2, &sig, NULL);
        }
    }
    final_display("map_usr_2_1.txt", "map_usr_1.txt");
}

void player_two(all_t *s_all)
{
    struct sigaction sig;

    sig.sa_handler = signal_handler;
    my_printf("waiting for enemy's attack...\n");
    while (global != SIGUSR2) {
        sigaction(SIGUSR1, &sig, NULL);
        sigaction(SIGUSR2, &sig, NULL);
    }
    while (global != SIGUSR1) {
        global = 0;
        if (check_attack(s_all, "map_usr_1_1.txt", "map_usr_2.txt", 2) == 2)
            return;
        kill(s_all->usr1, SIGUSR1);
        while (global != SIGUSR2 && global != SIGUSR1) {
            usleep(100000);
            sigaction(SIGUSR1, &sig, NULL);
            sigaction(SIGUSR2, &sig, NULL);
        }
    }
    final_display("map_usr_1_1.txt", "map_usr_2.txt");
}
