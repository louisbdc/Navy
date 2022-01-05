/*
** EPITECH PROJECT, 2021
** open_clear_write_file.c
** File description:
** Created by louis on 09/12/2021.
*/

#include "my.h"

char *file_3(char *file_2)
{
    char *new_file = my_strdup(file_2);

    if (new_file[8] == '1') {
        new_file[8] = '2';
    } else
        new_file[8] = '1';
    return (new_file);
}

void previous_attack(void)
{
    int fd = open("stock.txt", O_RDONLY);
    char *buffer = malloc(sizeof(char) * 12);
    int i = 0;

    read(fd, buffer, 11);
    close(fd);
    for (; buffer[i] != '\n'; i++);
    buffer[i + 1] = '\0';
    my_printf("%s", buffer);
    free(buffer);
}

void my_maps(char *file, char *file_2)
{
    char *new_file = file_3(file);
    int fd = open(new_file, O_RDONLY);
    char *map = malloc(sizeof(char) * (180));

    read(fd, map, 179);
    map[179] = '\0';
    close(fd);
    my_printf("\nmy positions:\n%s\n", map);
    free(map);
    fd = open(file_2, O_RDONLY);
    map = malloc(sizeof(char) * (180));
    read(fd, map, 179);
    map[179] = '\0';
    close(fd);
    my_printf("\nenemy's positions:\n%s\n\n", map);
    free(map);
}

void final_display(char *file, char *file_2)
{
    previous_attack();
    my_maps(file, file_2);
    my_printf("Enemy won\n");
}
