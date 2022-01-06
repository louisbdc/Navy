/*
** EPITECH PROJECT, 2021
** my.h
** File description:
** my
*/

#ifndef MY_H_
#define MY_H_
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include<sys/stat.h>
#include<time.h>
#include<fcntl.h>
#include<SFML/Config.h>
#include<SFML/Graphics.h>
#include<SFML/Audio.h>

void my_putchar(char c);
int my_putstr(char const *str);
int my_strlen(char const *str);
int my_put_nbr(int nb);
char *get_cleanstr(char *str);
int is_nbr(int a);
char get_char(int a);
int get_digit(char a);
int str_value_cmp(char *str1, char *str2);
char *my_strcat(char *dest,char const *src);
char *add_neg(char *str);
int yes_no(char *str1, char *str2);
char *get_lower(char *str1, char *str2);
char *delete_begin_zero(char *str);
char *get_lower(char *str1, char *str2);
char *my_strcpy(char *dest,char const *src);
char *my_strdup(char *src);
int get_total_number(int i, char const *str);
char *str_longer(char *str1, char *str2);
char *sub(char *str1, char *str2);
char *sum(char *str1, char *str2);
long str_to_long(char *str);
void my_print_nbrs(int a, ...);
long my_put_long(long nb);
void my_print_str(int a, ...);
unsigned int my_put_unsigned(unsigned int nb);
unsigned int my_put_octal(unsigned int nb);
unsigned long dec_to_bin(unsigned long a);
char *my_revstr(char *str);
int dec_to_oct(int a);
char *dec_to_hexa(int a);
int my_put_np_str(char const *str);
int nbrs_cmp(int a, int b, int c);
int my_printf(const char* str, ...);
char **map_result(int **map2, int x, int y, int sq_size, char **map);
char *my_itoa(int a);

#define WIDTH 1920
#define HEIGHT 1080

typedef struct para1
{
    sfSprite* s_p1;
    sfTexture* t_p1;
    sfVector2f pos_p1;
}para1_t;

typedef struct para2
{
    sfSprite* s_p2;
    sfTexture* t_p2;
    sfVector2f pos_p2;
}para2_t;

typedef struct para3
{
    sfSprite* s_p3;
    sfTexture* t_p3;
    sfVector2f pos_p3;
}para3_t;

typedef struct para4
{
    sfSprite* s_p4;
    sfTexture* t_p4;
    sfVector2f pos_p4;
}para4_t;

typedef struct para5
{
    sfSprite* s_p5;
    sfTexture* t_p5;
    sfVector2f pos_p5;
}para5_t;

typedef struct para6
{
    sfSprite* s_p6;
    sfTexture* t_p6;
    sfVector2f pos_p6;
}para6_t;

typedef struct para7
{
    sfSprite* s_p7;
    sfTexture* t_p7;
    sfVector2f pos_p7;
}para7_t;

typedef struct para
{
    para1_t *pa1;
    para2_t *pa2;
    para3_t *pa3;
    para4_t *pa4;
    para5_t *pa5;
    para6_t *pa6;
    para7_t *pa7;
}para_t;

typedef struct create_box
{
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f pos;
    struct create_box *next;
} t_create_box;

typedef struct game
{
    sfRenderWindow* win;
    sfVideoMode mode;
    sfEvent event;
    sfSprite* spt_back;
    sfSprite* spt_backm;
    sfTexture* txt_back;
    sfTexture* txt_backm;
    sfVector2f pos;
    sfMouseButtonEvent mouse;
    sfSprite* s_p1;
    sfTexture* t_p1;
    sfVector2f pos_p1;
    sfClock *cl1;
    sfSprite* s_p2;
    sfTexture* t_p2;
    sfVector2f pos_p2;
    sfClock *cl2;
    sfSprite* s_p3;
    sfTexture* t_p3;
    sfVector2f pos_p3;
    sfClock *cl3;
    sfSprite* s_p4;
    sfTexture* t_p4;
    sfVector2f pos_p4;
    sfClock *cl4;
    sfSprite* s_p5;
    sfTexture* t_p5;
    sfVector2f pos_p5;
    sfClock *cl5;
    sfSprite* s_p6;
    sfTexture* t_p6;
    sfVector2f pos_p6;
    sfClock *cl6;
    sfSprite* s_p7;
    sfTexture* t_p7;
    sfVector2f pos_p7;
    sfClock *cl7;
    sfSprite *s_man;
    sfSprite *s_jman;
    sfSprite *s_sman;
    sfTexture *t_man;
    sfTexture *t_jman;
    sfTexture *t_sman;
    sfIntRect man;
    sfIntRect jman;
    sfIntRect sman;
    sfVector2f pos_man;
    sfVector2f sc_man;
    sfClock *cl_man;
    int lock;
    sfSprite *s_blueb;
    sfTexture *t_blueb;
    sfIntRect blueb;
    sfVector2f pos_blueb;
    sfVector2f sc_blueb;
    sfSprite *s_redb;
    sfTexture *t_redb;
    sfIntRect redb;
    sfVector2f pos_redb;
    sfVector2f sc_redb;
    sfSprite *s_greenb;
    sfTexture *t_greenb;
    sfIntRect greenb;
    sfVector2f pos_greenb;
    sfVector2f pos_greenb1;
    sfVector2f sc_greenb;
    int menu;
    sfText *play;
    sfText *home;
    sfText *settings;
    sfText *quit;
    sfFont *font;
    sfVector2f pos_play;
    sfVector2f pos_home;
    sfVector2f pos_settings;
    sfVector2f pos_quit;
    t_create_box *s_create_box;
} game_t;


typedef struct man
{
    sfSprite *spt_man;
    sfTexture *txt_man;
    sfIntRect man_blue;
    sfVector2f pos_p1;
    sfClock *cl_blue;
} man_t;

typedef struct text
{
    sfText *score;
    sfFont *font;
    sfText *Game_ov;
    sfVector2f pos_game_ov;
    sfVector2f pos_score;
    int hitted;
} text_t;

typedef struct all
{
    game_t *w;
    para_t *pa;
} all_t;

void declare_man(game_t *game);
void slide(game_t *game);
void jump(game_t *game);
void declare_all(game_t *game, char **av);
void parse(char **av, game_t *game);
void declare_man2(game_t *game);
void set_man(game_t *game);
void set_jman(game_t *game);
void set_sman(game_t *game);
void reset_pos_sman(game_t *game);
void declare_buttons(game_t *game);
void declare_buttons2(game_t *game);
void manage_buttons(sfMouseButtonEvent event_mouse, game_t *game);
void manage_buttons2(sfMouseButtonEvent event_mouse, game_t *game);
void home_loop(game_t *game);
void set_p1(game_t *game);
void set_p2(game_t *game);
void set_p3(game_t *game);
void set_p4(game_t *game);
void set_p5(game_t *game);
void print_list(game_t *game);
char **get_map(char *str);
void mapall(char const *filepath);
char *get_map_str(char const *filepath);
void settings_loop(game_t *game);
void game_loop(game_t *game);
void game_loop(game_t *game);
void set_p(game_t *game);
void set_win(game_t *game);
void set_all(game_t *game);
void set_win_m(game_t *game);
void set_win_s(game_t *game);
void declare_text(game_t *game);
void declare_text2(game_t *game);
void set_text(game_t *game);
void set_text2(game_t *game);

#endif /* !MY_H_ */
