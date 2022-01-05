/*
** EPITECH PROJECT, 2022
** put the boat in the map
** File description:
** put the boat in the map
*/

#include "my.h"

char *array_to_char(char **map)
{
    char *str = malloc(sizeof(char) * 1);

    str[0] = '\0';
    for (int j = 0; map[j] != NULL; j++) {
        str = my_strdupcat(str, map[j]);
        str = my_strdupcat(str, "\n");
    }
    str[my_strlen(str) - 1] = '\0';
    return (str);
}

int put_char(char **map, char **position, int i)
{
    char nbr = position[i][2];
    int x = 0;
    int y;

    for (; map[0][x] != '\0'; x++) {
        if (map[0][x] == nbr)
            break;
    }
    for (; nbr <= position[i][5]; nbr++) {
        for (char nbr_2 = position[i][3] ; nbr_2 <= position[i][6]; nbr_2++) {
            y = nbr_2 - 48 + 1;
            if (map[y][x] >= '0' && map[y][x] <= '9')
                return (1);
            map[y][x] = position[i][0];
        }
        x += 2;
    }
    return (0);
}

int put_boat_2(char **position, char **map, char *file)
{
    FILE *fds = fopen(file, "w+");
    char *str;
    int fd;

    fclose(fds);
    fd = open(file, O_WRONLY);
    for (int i = 0; i < 4; i++) {
        if (put_char(map, position, i) == 1)
            return (1);
    }
    str = array_to_char(map);
    write(fd, str, 179);
    close(fd);
    free(str);
    free_tab(position);
    return (0);
}

int put_boat(char *pos, char *file)
{
    int fd_f = open(file, O_RDONLY);
    int fd_p = open(pos, O_RDONLY);
    char *position = malloc(sizeof(char) * 32);
    char *str = malloc(sizeof(char) * 180);
    char **map;
    int returned = 0;

    read(fd_p, position, 31);
    read(fd_f, str, 179);
    close(fd_p);
    close(fd_f);
    position[31] = '\0';
    str[179] = '\0';
    map = my_str_to_word_array(str);
    if (put_boat_2(my_str_to_word_array(position), map, file) == 1)
        returned = 1;
    free_tab(map);
    free(str);
    free(position);
    return (returned);
}
