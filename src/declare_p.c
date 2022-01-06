/*
** EPITECH PROJECT, 2021
** myrunner
** File description:
** parallax
*/

#include"../lib/my.h"

void declare_window(game_t *game)
{
    game->lock = 0;
    game->menu = 0;
    game->cl1 = sfClock_create();
    game->cl2 = sfClock_create();
    game->cl3 = sfClock_create();
    game->mode = (sfVideoMode) {WIDTH, HEIGHT, 32};
    game->pos = (sfVector2f) {0, 0};
    game->win = sfRenderWindow_create(game->mode, "o", sfFullscreen, NULL);
    game->spt_back = sfSprite_create();
    game->txt_back = sfTexture_create(WIDTH, HEIGHT);
    sfSprite_setTexture(game->spt_back, game->txt_back, sfFalse);
    sfRenderWindow_setFramerateLimit(game->win, 60);
}

void declare_windowm(game_t *game)
{
    game->spt_backm = sfSprite_create();
    game->txt_backm = sfTexture_createFromFile("./assets/menu.png", NULL);
    sfSprite_setTexture(game->spt_backm, game->txt_backm, sfFalse);
}

void declare_p1(game_t *game)
{
    game->s_p1 = sfSprite_create();
    game->pos_p1 = (sfVector2f) {0, 0};
    game->t_p1 = sfTexture_createFromFile("./assets/p/1.png", NULL);
    sfSprite_setTexture(game->s_p1, game->t_p1, sfFalse);
    game->s_p2 = sfSprite_create();
    game->pos_p2 = (sfVector2f) {0, 0};
    game->t_p2 = sfTexture_createFromFile("./assets/p/2.png", NULL);
    sfSprite_setTexture(game->s_p2, game->t_p2, sfFalse);
    game->s_p3 = sfSprite_create();
    game->pos_p3 = (sfVector2f) {0, 0};
    game->t_p3 = sfTexture_createFromFile("./assets/p/3.png", NULL);
    sfSprite_setTexture(game->s_p3, game->t_p3, sfFalse);
    game->s_p4 = sfSprite_create();
    game->pos_p4 = (sfVector2f) {0, 0};
    game->t_p4 = sfTexture_createFromFile("./assets/p/4.png", NULL);
    sfSprite_setTexture(game->s_p4, game->t_p4, sfFalse);
}

void declare_p2(game_t *game)
{
    game->cl4 = sfClock_create();
    game->cl5 = sfClock_create();
    game->cl6 = sfClock_create();
    game->cl7 = sfClock_create();
    game->s_p5 = sfSprite_create();
    game->pos_p5 = (sfVector2f) {0, 0};
    game->t_p5 = sfTexture_createFromFile("./assets/p/5.png", NULL);
    sfSprite_setTexture(game->s_p5, game->t_p5, sfFalse);
    game->s_p6 = sfSprite_create();
    game->pos_p6 = (sfVector2f) {0, 0};
    game->t_p6 = sfTexture_createFromFile("./assets/p/6.png", NULL);
    sfSprite_setTexture(game->s_p6, game->t_p6, sfFalse);
    game->s_p7 = sfSprite_create();
    game->pos_p7 = (sfVector2f) {0, 0};
    game->t_p7 = sfTexture_createFromFile("./assets/p/7.png", NULL);
    sfSprite_setTexture(game->s_p7, game->t_p7, sfFalse);
}

void declare_all(game_t *game, char **av)
{
    parse(av, game);
    declare_window(game);
    declare_windowm(game);
    declare_p1(game);
    declare_p2(game);
    declare_man(game);
    declare_man2(game);
    declare_buttons(game);
    declare_buttons2(game);
    declare_text(game);
    declare_text2(game);
}