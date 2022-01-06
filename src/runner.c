/*
** EPITECH PROJECT, 2021
** myhunter
** File description:
** hunter
*/

#include"../lib/my.h"

void analyse_events(game_t *game, sfEvent event)
{
    while (sfRenderWindow_pollEvent(game->win, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(game->win);
        if (event.type == sfEvtKeyPressed && event.key.code == sfKeyEscape)
            sfRenderWindow_close(game->win);
        if (event.type == sfEvtMouseButtonPressed) {
            manage_buttons(event.mouseButton, game);
        }
    }
}

void analyse_events2(game_t *game, sfEvent event)
{
    while (sfRenderWindow_pollEvent(game->win, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(game->win);
        if (event.type == sfEvtKeyPressed && event.key.code == sfKeyEscape)
            sfRenderWindow_close(game->win);
        if (event.type == sfEvtMouseButtonPressed) {
            manage_buttons2(event.mouseButton, game);
        }
    }
}

void game_loop(game_t *game)
{
        set_p(game);
        set_all(game);
        print_list(game);
        set_win(game);
        analyse_events(game, game->event);
}

void settings_loop(game_t *game)
{
    set_text2(game);
    set_win_s(game);
    analyse_events2(game, game->event);
}

void neil_game(game_t *game)
{
    while (sfRenderWindow_isOpen(game->win)) {
        if (game->menu == 0)
            home_loop(game);
        if (game->menu == 1)
            game_loop(game);
        if (game->menu == 2)
            settings_loop(game);
    }
}

void end_window(game_t *game)
{
    sfTexture_destroy(game->txt_back);
    sfSprite_destroy(game->spt_back);
    sfRenderWindow_destroy(game->win);
}

int main(int ac, char **av)
{
    game_t *game = malloc(sizeof(game_t));
    ac++;
    declare_all(game, av);
    neil_game(game);
    end_window(game);
    return 0;
}

// int main(int ac, char **av)
// {
//     parse(ac, av);
//     return 0;
// }