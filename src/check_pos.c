/*
** EPITECH PROJECT, 2021
** check_pos.c
** File description:
** Created by louis on 14/12/2021.
*/

#include "my.h"

int check_first_pos_and_double_dot(char **map)
{
    if (map[0][0] != '2' || map[1][0] != '3' || map[2][0] != '4'
        || map[3][0] != '5')
        return 84;
    if (map[0][1] != ':' || map[1][1] != ':' || map[2][1] != ':'
        || map[3][1] != ':')
        return 84;
    if (map[0][4] != ':' || map[1][4] != ':' || map[2][4] != ':'
        || map[3][4] != ':')
        return 84;
    return 0;
}

int check_alpha_num(char **map, int row)
{
    if (map[row][2] < 'A' || map[row][2] > 'H')
        return 84;
    if (map[row][5] < 'A' || map[row][5] > 'H')
        return 84;
    if (map[row][3] < '0' || map[row][3] > '8')
        return 84;
    if (map[row][6] < '0' || map[row][6] > '8')
        return 84;
    return 0;
}

int check_lines(char *file)
{
    char *buffer = open_file(file);
    if (buffer == NULL)
        return 84;
    char **map = my_str_to_word_array(buffer);
    if (check_first_pos_and_double_dot(map) == 84) {
        free_tab(map);
        return 84;
    }
    if (check_alpha_num(map, 0) == 84 || check_alpha_num(map, 1) == 84 ||
    check_alpha_num(map, 2) == 84 || check_alpha_num(map, 3) == 84) {
        free_tab(map);
        return 84;
    }
    if (check_intersect(map) == 84)
        return 84;
    free_tab(map);
    return 0;
}
