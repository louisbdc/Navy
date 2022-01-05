/*
** EPITECH PROJECT, 2021
** check_intersect.c
** File description:
** Created by louis on 14/12/2021.
*/

#include "my.h"

int same_x(char **array, int const *pos, int nb)
{
    int x = pos[POS_X_1];
    int y_1 = pos[POS_Y_1];
    int y_2 = pos[POS_Y_2];
    int i = 0;

    int little = y_1 > y_2 ? y_2 : y_1;
    int big = y_1 > y_2 ? y_1 : y_2;
    while (little <= big) {
        if (array[x][little] == 'x')
            return 84;
        else
            array[x][little] = 'x';
        little++;
        i++;
    }
    return i == nb ? 0 : 84;
}

int same_y(char **array, int const *pos, int nb)
{
    int y = pos[POS_Y_1];
    int x_1 = pos[POS_X_1];
    int x_2 = pos[POS_X_2];
    int i = 0;

    int little = x_1 > x_2 ? x_2 : x_1;
    int big = x_1 > x_2 ? x_1 : x_2;
    while (little <= big) {
        if (array[y][little] == 'x')
            return 84;
        else
            array[y][little] = 'x';
        little++;
        i++;
    }
    return i == nb ? 0 : 84;
}

int check_intersect_scd(int nb, char **array, int *pos)
{
    if (pos[POS_X_1] == pos[POS_X_2]) {
        if (same_x(array, pos, nb) == 84)
            return 84;
    } else if (pos[POS_Y_1] == pos[POS_Y_2]) {
        if (same_y(array, pos, nb) == 84)
            return 84;
    } else
        return 84;
    return 0;
}

int check_intersect(char **map)
{
    int i;
    char **array = malloc(sizeof(char *) * 9);
    int *pos = malloc(sizeof(int) * 4);
    for (i = 0; i < 9; i++)
        array[i] = malloc(sizeof(char) * 9);
    array[i] = NULL;
    for (i = 0; map[i] != NULL; i++) {
        pos[POS_X_1] = map[i][2] - 65;
        pos[POS_Y_1] = map[i][3] - 48;
        pos[POS_X_2] = map[i][5] - 65;
        pos[POS_Y_2] = map[i][6] - 48;
        if (check_intersect_scd(map[i][0] - 48, array, pos) == 84) {
            free_tab(array);
            return 84;
        }
    }
    return 0;
}
