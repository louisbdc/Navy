/*
** EPITECH PROJECT, 2022
** myrunner
** File description:
** liste
*/

#include "../lib/my.h"

t_create_box *init(void)
{
    t_create_box *node = malloc(sizeof(t_create_box));
    node->next = NULL;
    return node;
}

t_create_box *insert_box(game_t *game, int x, int y)
{
    t_create_box *node;
    node = malloc(sizeof(t_create_box));
    node->sprite = sfSprite_create();
    node->texture = sfTexture_createFromFile("assets/buttons.png", NULL);
    node->pos = (sfVector2f) {x *100, y * 100};
    sfSprite_setTexture(node->sprite, node->texture, sfFalse);
    sfSprite_setPosition(node->sprite, node->pos);
    node->next = game->s_create_box;
    game->s_create_box = node;
    return node;
}

void parse(char **av, game_t *game)
{
    game->s_create_box = init();
    char **map = get_map(get_map_str(av[1]));
    int i = 0;
    int j = 0;
    while (map[i] != NULL) {
        while (map[i][j] != '\0') {
            if (map[i][j] == '1') {
                game->s_create_box = insert_box(game, j, i);
            }
            j++;
        }
        j = 0;
        i++;
    }
}

void print_list(game_t *game)
{
    t_create_box *first_node = game->s_create_box;
    while(game->s_create_box != NULL) {
        sfRenderWindow_drawSprite(game->win, game->s_create_box->sprite, NULL);
        game->s_create_box = game->s_create_box->next;
    }
    game->s_create_box = first_node;
}