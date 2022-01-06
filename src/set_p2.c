/*
** EPITECH PROJECT, 2021
** myrunner
** File description:
** set2
*/

#include"../lib/my.h"

void set_p6(game_t *game)
{
    sfSprite_setPosition(game->s_p6, game->pos_p6);
    if (game->pos_p6.x <= -1920) {
        game->pos_p6.x = 0;
    }
    if (sfClock_getElapsedTime(game->cl6).microseconds > 1000) {
        game->pos_p6.x = game->pos_p6.x - 0.4;
        sfClock_restart(game->cl6);
    }
    sfRenderWindow_drawSprite(game->win, game->s_p6, NULL);
}

void set_p7(game_t *game)
{
    sfSprite_setPosition(game->s_p7, game->pos_p7);
    if (game->pos_p7.x <= -1920) {
        game->pos_p7.x = 0;
    }
    if (sfClock_getElapsedTime(game->cl7).microseconds > 1000) {
        game->pos_p7.x = game->pos_p7.x - 1;
        sfClock_restart(game->cl7);
    }
    sfRenderWindow_drawSprite(game->win, game->s_p7, NULL);
}

void set_p(game_t *game)
{
    sfSprite_setPosition(game->s_p7, game->pos_p7);
    sfRenderWindow_drawSprite(game->win, game->s_p7, NULL);
    sfSprite_setPosition(game->s_p6, game->pos_p6);
    sfRenderWindow_drawSprite(game->win, game->s_p6, NULL);
    sfSprite_setPosition(game->s_p5, game->pos_p5);
    sfRenderWindow_drawSprite(game->win, game->s_p5, NULL);
    sfSprite_setPosition(game->s_p4, game->pos_p4);
    sfRenderWindow_drawSprite(game->win, game->s_p4, NULL);
    sfSprite_setPosition(game->s_p3, game->pos_p3);
    sfRenderWindow_drawSprite(game->win, game->s_p3, NULL);
    sfSprite_setPosition(game->s_p2, game->pos_p2);
    sfRenderWindow_drawSprite(game->win, game->s_p2, NULL);
}

void set_win(game_t *game)
{
    sfSprite_setPosition(game->spt_back, game->pos);
    sfRenderWindow_drawSprite(game->win, game->spt_back, NULL);
    sfRenderWindow_display(game->win);
    sfRenderWindow_clear(game->win, sfBlack);
}

void set_all(game_t *game)
{
    set_p7(game);
    set_p6(game);
    set_p5(game);
    set_p4(game);
    set_p3(game);
    set_p2(game);
    set_p1(game);
    if (game->lock == 0)
        set_man(game);
    if (game->lock == 1 || game->lock == 2)
        set_jman(game);
    if (game->lock == 3)
        set_sman(game);
    jump(game);
    slide(game);
}