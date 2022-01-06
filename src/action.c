/*
** EPITECH PROJECT, 2022
** myrunner
** File description:
** action
*/

#include"../lib/my.h"

void jump(game_t *game)
{
    if (sfKeyboard_isKeyPressed(sfKeySpace) == sfTrue && game->lock == 0)
        game->lock = 1;
    if (sfKeyboard_isKeyPressed(sfKeySpace) == sfTrue && game->lock == 1)
        game->pos_man.y -= 10;
    else if (game->pos_man.y <= 700)
        game->lock = 2;
    if (game->pos_man.y <= 400)
        game->lock = 2;
    if (game->lock == 2)
        game->pos_man.y += 10;
    if (game->lock == 2 && game->pos_man.y >= 700)
        game->lock = 0;
    sfSprite_setPosition(game->s_jman, game->pos_man);
}

void slide(game_t *game)
{
    if (sfKeyboard_isKeyPressed(sfKeyS) == sfTrue && game->lock == 0)
        game->lock = 3;
    if (sfKeyboard_isKeyPressed(sfKeyS) == sfTrue && game->lock == 3)
        game->pos_man.y = 800;
    if (sfKeyboard_isKeyPressed(sfKeyS) == sfFalse && game->lock == 3) {
        game->pos_man.y = 670;
        game->lock = 0;
    }
    sfSprite_setPosition(game->s_sman, game->pos_man);
}