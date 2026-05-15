#include "../include/philosophers.h"

void    init_philos(t_pars pars, t_philo *philo)
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
        i++;
    }
}

void    init_forks(t_pars pars, t_mutex **forks)
{
    int     i;

    i = 0;
    while (i < pars.nb_fork)
    {
        if (pthread_mutex_init(forks[i], NULL) != 0)
            error(RED"Pthread_mutex_init: error"RESET, 1);//LIBER TOUT JONA STPPP
        i++;
    }
}