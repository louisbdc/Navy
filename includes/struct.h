/*
** EPITECH PROJECT, 2021
** struct
** File description:
** struct with x, y and size max
*/

#ifndef STRUCT_H_
    #define STRUCT_H_
    #include "my.h"

    #define POS_X_1 0
    #define POS_Y_1 1
    #define POS_X_2 2
    #define POS_Y_2 3

typedef struct structure {
    int i;
    int after_modulo;
    int nbr_0_before;
    int nbr_0;
    int print;
    int plus;
    int space;
    int diez;
    int char0;
}struct_t;

typedef struct all_t {
    struct sigaction sig;
    int pid1;
    int pid2;
    int usr1;
    int usr2;
    int nb_hit_boat;
}all_t;

int my_strcmp_2(char const *s1, char const *s2);
char **my_str_to_word_array(char *str);
void display();
char *prompt();
char *open_file(char *file);
int dash_h(char *file);
void play(all_t *s_all);
int player_one_begining(all_t *s_all);
int player_two_begining(all_t *s_all);
void signal_handler_1(int signo, siginfo_t *info);
void signal_handler(int signo);
void player_one(all_t *s_all);
void player_two(all_t *s_all);
int check_lines(char *file);
void free_tab(char **tab);
int check_intersect(char **map);
int write_file(char *file, char *file_2, char *coor);
int reset(char *file, char *file_2, char *pos);
void my_maps(char *file, char *file_2);
int check_coor(char *file, char *coor);
int put_boat(char *pos, char *file);
void previous_attack(void);
int is_the_end(all_t *s_all, int nb, int usr);
void final_display(char *file, char *file_2);

#endif
