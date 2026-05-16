#include "../include/philosophers.h"

void    init_philos(t_pars pars, t_philo *philo, t_mutex *fork)
{
    int     i;

    i = 0;
    while (i < pars.nb_philo)
    {
        philo[i].index = i;
        philo[i].time.die = (size_t)pars.t_die;
        philo[i].time.eat = (size_t)pars.t_eat;
        philo[i].time.sleep = (size_t)pars.t_sleep;
        philo[i].time.prev_eat = get_time();
        philo[i].time.birth_time = get_time();
        philo[i].eat_objct = (int)pars.num_eat;
        philo[i].eat_count = 0;
        ft_strcpy(philo[i].name, find_philo(philo[i].time.birth_time));
        usleep(900);
        philo[i].left_fork = &fork[i];
        if (i == 0)
            philo[i].right_fork = &fork[pars.nb_fork - 1];
        else
            philo[i].right_fork = &fork[i - 1];
        i++;
    }
}

void    init_gc(t_free_all *gc, t_mutex *fork, t_philo *philos, t_pars parser)
{
    gc->forks = fork;
    gc->philos = philos;
    gc->nb = parser.nb_philo;
}

void    init_forks(t_free_all gc, t_pars pars, t_mutex *forks)
{
    int     i;

    i = 0;
    while (i < pars.nb_fork)
    {
        if (pthread_mutex_init(&forks[i], NULL) != 0)
            free_all(&gc, RED"Pthread_mutex_init: error"RESET, 1);
        i++;
    }
}