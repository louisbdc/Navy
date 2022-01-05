/*
** EPITECH PROJECT, 2021
** init
** File description:
** init struct
*/

#include "my.h"

void reset_2(char *map, char *file, char *file_2)
{
    int fd = open(file, O_WRONLY);

    write(fd, map, 179);
    close(fd);
    fd = open(file_2, O_WRONLY);
    write(fd, map, 179);
    close(fd);
    fd = open("stock.txt", O_WRONLY);
    write(fd, "\n", 1);
    close(fd);
}

int reset(char *file, char *file_2, char *pos)
{
    FILE *fd = fopen(file, "w+");
    int fds = open("map.txt", O_RDONLY);
    char *map = malloc(sizeof(char) * 180);

    fclose(fd);
    fd = fopen(file_2, "w+");
    fclose(fd);
    fd = fopen("stock.txt", "w+");
    fclose(fd);
    read(fds, map, 179);
    close(fds);
    map[179] = '\0';
    reset_2(map, file, file_2);
    return (put_boat(pos, file));
}
