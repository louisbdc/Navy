/*
** EPITECH PROJECT, 2021
** myprintf
** File description:
** my_str_funct
*/

#include "my.h"

int my_strlen(char const *str)
{
    int a = 0;

    while (str[a] != '\0') {
        a = a + 1;
    }
    return a;
}

char *my_strdup(char *src)
{
   int i = my_strlen(src);
   char *dest = malloc (sizeof(char) * (i + 1));

    for (i = 0; src[i] != '\0'; i++) {
        dest[i] = src[i];
    }
    dest[i] = '\0';
    return dest;
}

char *my_strcpy(char *dest, char const *src)
{
    int i;

    for ( i = 0; src[i] != '\0'; i++) {
        dest[i] = src[i];
    }
    dest[i] = '\0';
    return dest;
}

char *my_strcat(char *dest, char const *src)
{
    int i = my_strlen(dest);
    char *res = malloc(sizeof(char) * 100);

    for (int j = 0; dest[j] != '\0'; j++) {
        res[j] = dest[j];
    }
    for (int j = 0; src[j] != '\0'; i++) {
        res[i] = src[j];
        j++;
    }
    res[i] = '\0';
    return res;
}

char *my_revstr(char *str)
{
    int a = my_strlen(str) - 1;
    char temp;

    for (int i = 0; i < a; i++, a--) {
        temp = str[i];
        str[i] = str[a];
        str[a] = temp;
    }
    return (str);
}