/*
** EPITECH PROJECT, 2021
** myprintf
** File description:
** my_put_funct
*/

#include "my.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

int my_putstr(char const *str)
{
    for (int a = 0; str[a] != '\0'; a++)
	    my_putchar(str[a]);
    return 0;
}
