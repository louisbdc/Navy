/*
** EPITECH PROJECT, 2021
** open_clear_write_file.c
** File description:
** Created by louis on 09/12/2021.
*/

#include "my.h"

char *open_file(char *file)
{
    int fd = open(file, O_RDONLY);
    if (fd == -1)
        return NULL;
    char *map = NULL;
    map = malloc(sizeof(char) * (32));
    read(fd, map, 31);
    map[31] = '\0';
    close(fd);
    return map;
}

void clean_file(char *file, char *map)
{
    FILE *fd = fopen(file, "w+");
    int fds;

    fclose(fd);
    fds = open(file, O_WRONLY);
    write(fds, map, 179);
    close(fds);
}

void stock(char *file, char *coor)
{
    FILE *fd = fopen("stock.txt", "w+");
    char *str = my_strdupcat(coor, file);
    int fds;
    int length;

    fclose(fd);
    fds = open("stock.txt", O_WRONLY);
    length = my_strlen(str);
    write(fds, str, length);
    close(fds);
    free(str);
}

int write_file_2(char *file_2, int coo, char touch, char *coor)
{
    int fd = open(file_2, O_RDONLY);
    char *map_2 = malloc(sizeof(char) * 180);
    int returned = 0;

    read(fd, map_2, 179);
    map_2[179] = '\0';
    close(fd);
    map_2[coo] = touch;
    coor[2] = '\0';
    clean_file(file_2, map_2);
    if (touch == 'x') {
        my_printf("%s: hit\n\n", coor);
        stock(": hit\n", coor);
        returned = 1;
    } else {
        my_printf("%s: missed\n\n", coor);
        stock(": missed\n", coor);
    }
    free(map_2);
    return (returned);
}

int write_file(char *file, char *file_2, char *coor)
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
    if (map[i] >= '1' && map[i] <= '8') {
        map[i] = 'x';
    } else
        map[i] = 'o';
    clean_file(file, map);
    i = write_file_2(file_2, i, map[i], coor);
    free(map);
    return (i);
}
