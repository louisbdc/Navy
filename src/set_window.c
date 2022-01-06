/*
** EPITECH PROJECT, 2022
** myrunner
** File description:
** set_menu
*/

#include"../lib/my.h"

void set_win_m(game_t *game)
{
    sfSprite_setPosition(game->spt_backm, game->pos);
    sfSprite_setPosition(game->s_greenb, game->pos_greenb);
    sfRenderWindow_drawSprite(game->win, game->spt_backm, NULL);
    sfRenderWindow_drawSprite(game->win, game->s_blueb, NULL);
    sfRenderWindow_drawSprite(game->win, game->s_redb, NULL);
    sfRenderWindow_drawSprite(game->win, game->s_greenb, NULL);
    sfRenderWindow_drawText(game->win, game->play, NULL);
    sfRenderWindow_drawText(game->win, game->settings, NULL);
    sfRenderWindow_drawText(game->win, game->quit, NULL);
    sfRenderWindow_display(game->win);
    sfRenderWindow_clear(game->win, sfBlack);
}

void set_win_s(game_t *game)
{
    sfSprite_setPosition(game->spt_backm, game->pos);
    sfSprite_setPosition(game->s_greenb, game->pos_greenb1);
    sfRenderWindow_drawSprite(game->win, game->spt_backm, NULL);
    sfRenderWindow_drawSprite(game->win, game->s_greenb, NULL);
    sfRenderWindow_drawText(game->win, game->home, NULL);
    sfRenderWindow_display(game->win);
    sfRenderWindow_clear(game->win, sfBlack);
}