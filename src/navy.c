/*
** EPITECH PROJECT, 2021
** navy.c
** File description:
** Created by louis on 08/12/2021.
*/

#include "my.h"

int global = 0;

void signal_handler(int signo)
{
    signal(signo, signal_handler);
    global = signo;
}

void signal_handler_1(int signo, siginfo_t *info)
{
    signal(signo, signal_handler);
    global = info->si_pid;
}

int usr_1(char **av, all_t *s_all)
{
    struct sigaction sig;

    s_all->usr1 = getpid();
    if (reset("map_usr_1_1.txt", "map_usr_1.txt", av[1]))
        return (84);
    sig.sa_handler = signal_handler_1;
    my_printf("my_pid: %i\n", s_all->usr1);
    my_printf("waiting for enemy connection...\n\n");
    while (global == 0) {
        sigaction(SIGUSR1, &sig, NULL);
        sigaction(SIGUSR2, &sig, NULL);
    }
    sig.sa_handler = signal_handler;
    s_all->usr2 = global;
    my_printf("enemy connected");
    kill(s_all->usr2, SIGUSR2);
    usleep(1000000);
    global = 0;
    player_one(s_all);
    return 0;
}

int usr_2(char **av, all_t *s_all)
{
    struct sigaction sig;

    s_all->usr2 = getpid();
    if (reset("map_usr_2_1.txt", "map_usr_2.txt", av[2]) == 1)
        return (84);
    sig.sa_handler = signal_handler;
    my_printf("my_pid: %i\n", s_all->usr2);
    kill(my_atoi(av[1]), SIGUSR1);
    while (global != SIGUSR2) {
        sigaction(SIGUSR1, &sig, NULL);
        sigaction(SIGUSR2, &sig, NULL);
    }
    s_all->usr1 = my_atoi(av[1]);
    my_printf("successfully connected\n");
    my_maps("map_usr_1_1.txt", "map_usr_2.txt");
    kill(s_all->usr1, SIGUSR1);
    usleep(1000000);
    global = 0;
    player_two(s_all);
    return 0;
}

int main(int ac, char **av)
{
    all_t *s_all = malloc(sizeof(all_t));

    if (ac == 2 && my_strcmp(av[1], "-h") == 0)
        return dash_h("h.txt");
    if ((ac == 2) && ((my_strcmp(av[1], "pos1") == 0
    && check_lines(av[1]) != 84)
    || (my_strcmp(av[1], "pos2") == 0
    && check_lines(av[1]) != 84)))
        return (usr_1(av, s_all));
    if (ac == 3 && ((my_strcmp(av[2], "pos2") == 0
    && check_lines(av[2]) != 84)
    || (my_strcmp(av[2], "pos1") == 0
    && check_lines(av[2]) != 84)))
        return (usr_2(av, s_all));
    return (84);
}
