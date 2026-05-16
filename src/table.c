#include "../include/philosophers.h"

static void    philo_turn_next(t_philo *philo)
{
    pthread_mutex_lock(philo->left_fork);
    printf(RED"philo %i: "BLUE"%s: "GREEN"has taken a fork\n"RESET, philo->index, philo->name);
    pthread_mutex_lock(philo->right_fork);
    printf(RED"philo %i: "BLUE"%s: "GREEN"has taken a fork\n"RESET, philo->index, philo->name);
    printf(RED"philo %i: "BLUE"%s: "GREEN"is eating\n"RESET, philo->index, philo->name);
    philo->time.prev_eat = get_time();
    philo->eat_count += 1;
    ft_usleep(philo->time.eat);
    pthread_mutex_unlock(philo->left_fork);
    pthread_mutex_unlock(philo->right_fork);
    printf(RED"philo %i: "BLUE"%s: "GREEN"is sleeping\n"RESET, philo->index, philo->name);  
    ft_usleep(philo->time.sleep);
    printf(RED"philo %i: "BLUE"%s: "GREEN"is thinking\n"RESET, philo->index, philo->name);
}

static void    *philo_turn(void *ptr)
{
    t_philo *philo;
    int     i;

    i = -1;
    philo = (t_philo *)ptr;
    if (philo->index % 2 == 0)
        ft_usleep(1);
    while (++i < 5)
        philo_turn_next(philo);
    return (NULL);
}

void    init_table(t_free_all *gc)
{
    // pthread_t checker;
    int     i;

    i = 0;
    while (i < gc->nb)
    {
        if (pthread_create(&gc->philos[i].thread_id, NULL, philo_turn, &gc->philos[i]) != 0)
            free_all(gc, RED"pthread_creat: Error\n"RESET, 1);
        i++;
    }
    i = 0;
    while (i < gc->nb)
    {
        pthread_join(gc->philos[i].thread_id, NULL);
        i++;
    }
}