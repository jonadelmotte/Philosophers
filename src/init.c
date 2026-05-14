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
        i++;
    }
}