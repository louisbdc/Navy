/*
** EPITECH PROJECT, 2022
** myrunner
** File description:
** game
*/

#include"../lib/my.h"

void declare_text(game_t *game)
{
    game->play = sfText_create();
    game->settings = sfText_create();
    game->quit = sfText_create();
    game->font = sfFont_createFromFile("./assets/font/bold.ttf");
    game->pos_play = (sfVector2f) {840, 340};
    game->pos_settings = (sfVector2f) {780, 520};
    game->pos_quit = (sfVector2f) {840, 690};
    sfText_setCharacterSize (game->play, 60);
    sfText_setCharacterSize (game->settings, 55);
    sfText_setCharacterSize (game->quit, 60);
    sfText_setColor(game->play, sfBlack);
    sfText_setColor(game->quit, sfBlack);
    sfText_setColor(game->settings, sfBlack);
    sfText_setFont(game->play, game->font);
    sfText_setFont(game->settings, game->font);
    sfText_setFont(game->quit, game->font);
}

void declare_text2(game_t *game)
{
    game->home = sfText_create();
    game->pos_home = (sfVector2f) {130, 950};
    sfText_setCharacterSize (game->home, 60);
    sfText_setColor(game->home, sfBlack);
    sfText_setFont(game->home, game->font);
}


void set_text(game_t *game)
{
    sfText_setString(game->play, "Play");
    sfText_setString(game->settings, "Settings");
    sfText_setString(game->quit, "Quit");
    sfText_setPosition(game->play, game->pos_play);
    sfText_setPosition(game->settings, game->pos_settings);
    sfText_setPosition(game->quit, game->pos_quit);
    sfRenderWindow_drawText(game->win, game->settings, NULL);
    sfRenderWindow_drawText(game->win, game->play, NULL);
    sfRenderWindow_drawText(game->win, game->quit, NULL);
}

void set_text2(game_t *game)
{
    sfText_setString(game->home, "Home");
    sfText_setPosition(game->home, game->pos_home);
    sfRenderWindow_drawText(game->win, game->home, NULL);
}