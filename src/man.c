/*
** EPITECH PROJECT, 2021
** myrunner
** File description:
** man
*/

#include"../lib/my.h"

void declare_man(game_t *game)
{
    game->s_man = sfSprite_create();
    game->s_jman = sfSprite_create();
    game->t_man = sfTexture_createFromFile("./assets/run.png", NULL);
    game->t_jman = sfTexture_createFromFile("./assets/jump.png", NULL);
    game->man = (sfIntRect) {0, 0, 417, 509};
    game->jman = (sfIntRect) {0, 0, 409, 538};
    game->pos_man = (sfVector2f) {0, 670};
    game->cl_man =sfClock_create();
    game->sc_man = (sfVector2f) {0.5, 0.5};
    sfSprite_setTexture(game->s_man, game->t_man, sfFalse);
    sfSprite_setTexture(game->s_jman, game->t_jman, sfFalse);
    sfSprite_setTextureRect(game->s_man, game->man);
    sfSprite_setTextureRect(game->s_jman, game->jman);
    sfSprite_setScale(game->s_man, game->sc_man);
    sfSprite_setScale(game->s_jman, game->sc_man);
    sfSprite_setPosition(game->s_man, game->pos_man);
    sfSprite_setPosition(game->s_jman, game->pos_man);
}

void declare_man2(game_t *game)
{
    game->s_sman = sfSprite_create();
    game->t_sman = sfTexture_createFromFile("./assets/slide.png", NULL);
    game->sman = (sfIntRect) {0, 0, 396, 391};
    sfSprite_setTexture(game->s_sman, game->t_sman, sfFalse);
    sfSprite_setTextureRect(game->s_sman, game->sman);
    sfSprite_setScale(game->s_sman, game->sc_man);
    sfSprite_setPosition(game->s_sman, game->pos_man);
}

void set_man(game_t *game)
{
    if (sfClock_getElapsedTime(game->cl_man).microseconds > 100000) {
        if (game->man.left == 1251) {
            game->man.left = 0;
            game->man.top += 509;
        }
        else if(game->man.top == 1018 && game->man.left == 417) {
            game->man.top = 0;
            game->man.left = 0;
        }
        else
            game->man.left +=417;
        sfSprite_setTextureRect(game->s_man, game->man);
        sfClock_restart(game->cl_man);
    }
    if (game->lock == 0)
        sfRenderWindow_drawSprite(game->win, game->s_man, NULL);
}

void set_jman(game_t *game)
{
    if (sfClock_getElapsedTime(game->cl_man).microseconds > 100000) {
        if (game->jman.left == 1227) {
            game->jman.left = 0;
            game->jman.top += 538;
        }
        else if(game->jman.top == 1076 && game->jman.left == 409) {
            game->jman.top = 0;
            game->jman.left = 0;
        }
        else
            game->jman.left += 409;
        sfSprite_setTextureRect(game->s_jman, game->jman);
        sfClock_restart(game->cl_man);
    }
    if (game->lock == 1 || game->lock == 2)
        sfRenderWindow_drawSprite(game->win, game->s_jman, NULL);
}

void set_sman(game_t *game)
{
    if (sfClock_getElapsedTime(game->cl_man).microseconds > 100000) {
        if (game->sman.left == 1188) {
            game->sman.left = 0;
            game->sman.top += 391;
        }
        else if(game->sman.top == 391 && game->sman.left == 792) {
            game->sman.top += 391;
            game->sman.left = 0;
        }
        else if(game->sman.top == 782 && game->sman.left == 792)
            reset_pos_sman(game);
        else
            game->sman.left += 396;
        sfSprite_setTextureRect(game->s_sman, game->sman);
        sfClock_restart(game->cl_man);
    }
    if (game->lock == 3)
        sfRenderWindow_drawSprite(game->win, game->s_sman, NULL);
}