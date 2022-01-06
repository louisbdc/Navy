/*
** EPITECH PROJECT, 2022
** myrunner
** File description:
** map
*/

#include"../lib/my.h"

char *get_map_str(char const *filepath)
{
    char *buffer;
    buffer = malloc(sizeof(char) * 1000);
    int fd = open(filepath, O_RDONLY);
    int i = read(fd, buffer, 100005);
    buffer[i] = '\0';
    return buffer;
}

char **get_map(char *str)
{
    int j = 0;
    int k = 0;
    char **map;

    map = malloc(sizeof(char *) * my_strlen(str) + 1);
    for (int i = 0; str[i] != '\0'; i++) {
        map[j] = malloc(sizeof(char) * my_strlen(str) + 1);
        while (str[i] != '\n' && str[i] != '\0') {
            map[j][k] = str[i];
            k++;
            i++;
        }
    map[j][k] = '\n';
    k = 0;
    j++;
    }
    map[j] = NULL;
    return map;
}

void print_tab(char **map)
{
    for (int i = 0; map[i] != NULL; i++)
        my_putstr(map[i]);
}

void mapall(char const *filepath)
{
    char *str;
    char **map;
    str = malloc(sizeof(char) * 100008);
    str = get_map_str(filepath);
    my_putstr(str);
    map = get_map(str);
    print_tab(map);
}