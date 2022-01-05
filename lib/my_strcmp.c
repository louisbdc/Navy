/*
** EPITECH PROJECT, 2021
** my_strcmp
** File description:
** compare 2 str
*/
#include <stdio.h>
#include <unistd.h>

int my_strlen(char const *str);

int my_strcmp(char const *s1, char const *s2)
{
    int limit;

    if (my_strlen(s1) > my_strlen(s2)) {
        limit = my_strlen(s2);
    } else {
        limit = my_strlen(s1);
    }
    for (int i = 0; i < limit; i++) {
        if (s1[i] > s2[i])
            return (1);
        if (s1[i] < s2[i])
            return (-1);
    }
    if (my_strlen(s1) > my_strlen(s2))
        return (1);
    if (my_strlen(s1) < my_strlen(s2))
        return (-1);
    return (0);
}

int my_strcmp_2(char const *s1, char const *s2)
{
    int limit;

    if (my_strlen(s1) > my_strlen(s2)) {
        limit = my_strlen(s2);
    } else {
        limit = my_strlen(s1);
    }
    for (int i = 0; i < limit; i++) {
        if (s1[i] > s2[i])
            return (1);
        if (s1[i] < s2[i])
            return (-1);
    }
    if (my_strlen(s1) - 1 > my_strlen(s2))
        return (1);
    if (my_strlen(s1) - 1 < my_strlen(s2))
        return (-1);
    return (0);
}
