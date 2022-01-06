/*
** EPITECH PROJECT, 2021
** bsq
** File description:
** nbrs_cmp
*/

#include<stdio.h>
#include"my.h"

int nbrs_cmp(int a, int b, int c)
{
    if (a <= b && a < c)
        return a;
    else if (a < b && a <= c)
        return a;
    else if (b <= a && b < c)
        return b;
    else if (b < a && b <= c)
        return b;
    else
        return c;
}

int pos_bsq(int **map3)
{
    
}