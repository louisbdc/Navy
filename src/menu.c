/*
** EPITECH PROJECT, 2022
** myrunner
** File description:
** menu
*/

#include"../lib/my.h"

void declare_buttons(game_t *game)
{
    game->s_blueb = sfSprite_create();
    game->s_redb = sfSprite_create();
    game->t_blueb = sfTexture_createFromFile("./assets/buttons.png", NULL);
    game->t_redb = sfTexture_createFromFile("./assets/buttons.png", NULL);
    game->blueb = (sfIntRect) {800, 400, 1400, 600};
    game->redb = (sfIntRect) {800, 1800, 1400, 2100};
    game->pos_blueb = (sfVector2f) {750, 300};
    game->pos_redb = (sfVector2f) {750, 640};
    game->pos_greenb = (sfVector2f) {750, 470};
    game->sc_blueb = (sfVector2f) {0.25, 0.25};
    game->sc_redb = (sfVector2f) {0.25, 0.25};
    sfSprite_setTexture(game->s_blueb, game->t_blueb, sfFalse);
    sfSprite_setTextureRect(game->s_blueb, game->blueb);
    sfSprite_setScale(game->s_blueb, game->sc_blueb);
    sfSprite_setPosition(game->s_blueb, game->pos_blueb);
    sfSprite_setTexture(game->s_redb, game->t_redb, sfFalse);
    sfSprite_setTextureRect(game->s_redb, game->redb);
    sfSprite_setScale(game->s_redb, game->sc_redb);
    sfSprite_setPosition(game->s_redb, game->pos_redb);
}

void declare_buttons2(game_t *game)
{
    game->s_greenb = sfSprite_create();
    game->t_greenb = sfTexture_createFromFile("./assets/buttons.png", NULL);
    game->greenb = (sfIntRect) {800, 1100, 1400, 620};
    game->pos_greenb = (sfVector2f) {750, 470};
    game->pos_greenb1 = (sfVector2f) {50, 900};
    game->sc_greenb = (sfVector2f) {0.25, 0.25};
    sfSprite_setTexture(game->s_greenb, game->t_greenb, sfFalse);
    sfSprite_setTextureRect(game->s_greenb, game->greenb);
    sfSprite_setScale(game->s_greenb, game->sc_greenb);
}

void manage_buttons(sfMouseButtonEvent event_mouse, game_t *game)
{
    if (event_mouse.x >= game->pos_blueb.x && event_mouse.x
    <= (game->pos_blueb.x + 340)
    && event_mouse.y >= game->pos_blueb.y
    && event_mouse.y <= (game->pos_blueb.y + 150)) {
        game->menu = 1;
    }
    if (event_mouse.x >= game->pos_redb.x && event_mouse.x
    <= (game->pos_redb.x + 340)
    && event_mouse.y >= game->pos_redb.y
    && event_mouse.y <= (game->pos_redb.y + 150)) {
        sfRenderWindow_close(game->win);
    }
    if (event_mouse.x >= game->pos_greenb.x && event_mouse.x
    <= (game->pos_greenb.x + 340)
    && event_mouse.y >= game->pos_greenb.y
    && event_mouse.y <= (game->pos_greenb.y + 150)) {
        game->menu = 2;
    }
}

void manage_buttons2(sfMouseButtonEvent event_mouse, game_t *game)
{
    if (event_mouse.x >= game->pos_greenb1.x && event_mouse.x
    <= (game->pos_greenb1.x + 340)
    && event_mouse.y >= game->pos_greenb1.y
    && event_mouse.y <= (game->pos_greenb1.y + 150)) {
        game->menu = 0;
    }
}

void home_loop(game_t *game)
{
    set_win_m(game);
    set_text(game);
    analyse_events(game, game->event);
}
