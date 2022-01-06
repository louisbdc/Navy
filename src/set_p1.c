/*
** EPITECH PROJECT, 2021
** myrunner
** File description:
** set1
*/

#include"../lib/my.h"

void set_p1(game_t *game)
{
    sfSprite_setPosition(game->s_p1, game->pos_p1);
    if (game->pos_p1.x <= -1920) {
        game->pos_p1.x = 0;
    }
    if (sfClock_getElapsedTime(game->cl1).microseconds > 1000) {
        game->pos_p1.x = game->pos_p1.x - 3.5;
        sfClock_restart(game->cl1);
    }
    sfRenderWindow_drawSprite(game->win, game->s_p1, NULL);
}

void set_p2(game_t *game)
{
    sfSprite_setPosition(game->s_p2, game->pos_p2);
    if (game->pos_p2.x <= -1920) {
        game->pos_p2.x = 0;
    }
    if (sfClock_getElapsedTime(game->cl2).microseconds > 1000) {
        game->pos_p2.x = game->pos_p2.x - 2;
        sfClock_restart(game->cl2);
    }
    sfRenderWindow_drawSprite(game->win, game->s_p2, NULL);
}

void set_p3(game_t *game)
{
    sfSprite_setPosition(game->s_p3, game->pos_p3);
    if (game->pos_p3.x <= -1920) {
        game->pos_p3.x = 0;
    }
    if (sfClock_getElapsedTime(game->cl3).microseconds > 1000) {
        game->pos_p3.x = game->pos_p3.x - 1.5;
        sfClock_restart(game->cl3);
    }
    sfRenderWindow_drawSprite(game->win, game->s_p3, NULL);
}

void set_p4(game_t *game)
{
    sfSprite_setPosition(game->s_p4, game->pos_p4);
    if (game->pos_p4.x <= -1920) {
        game->pos_p4.x = 0;
    }
    if (sfClock_getElapsedTime(game->cl4).microseconds > 1000) {
        game->pos_p4.x = game->pos_p4.x - 1;
        sfClock_restart(game->cl4);
    }
    sfRenderWindow_drawSprite(game->win, game->s_p4, NULL);
}

void set_p5(game_t *game)
{
    sfSprite_setPosition(game->s_p5, game->pos_p5);
    if (game->pos_p5.x <= -1920) {
        game->pos_p5.x = 0;
    }
    if (sfClock_getElapsedTime(game->cl5).microseconds > 1000) {
        game->pos_p5.x = game->pos_p5.x - 0.5;
        sfClock_restart(game->cl5);
    }
    sfRenderWindow_drawSprite(game->win, game->s_p5, NULL);
}