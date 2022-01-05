/*
** EPITECH PROJECT, 2021
** base
** File description:
** convert an int into a custom base
*/

#include "../../includes/my.h"

char *base(long long nbr, char *convert_into)
{
    char *str_nbr = my_int_str(nbr);
    char *result = malloc(sizeof(char) * my_strlen(str_nbr));
    long long i = 0;

    for (; nbr != 0; i++) {
        result[i] = convert_into[nbr % my_strlen(convert_into)];
        nbr /= my_strlen(convert_into);
    }
    result[i] = '\0';
    return (my_revstr(result));
}
