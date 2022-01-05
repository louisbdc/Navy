/*
** EPITECH PROJECT, 2021
** check coor
** File description:
** check if the coordonnées are great
*/

#include "my.h"

int check_coor(char *file, char *coor)
{
    int fd = open(file, O_RDONLY);
    int i = 0;
    char *map = malloc(sizeof(char) * (180));

    read(fd, map, 179);
    map[179] = '\0';
    close(fd);
    for (; i < 180; i++) {
        if (map[i] == coor[0])
            break;
    }
    for (int j = 0; j <= coor[1] - 48; j++)
        i += 18;
    if (map[i] == 'o' || map[i] == 'x')
        return (1);
    return (0);
}
