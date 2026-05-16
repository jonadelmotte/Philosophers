#include "../include/philosophers.h"

size_t ft_strlen(char *str)
{
    size_t i;

    i = 0;
    while (str[i])
        i++;
    return (i);
}

size_t	ft_strcpy(char *dest, const char *src)
{
	size_t	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (0);
}

void    error(char *str, int out)
{
    if (str)
        write(2, str, ft_strlen(str) + 1);
    exit(out);
}

size_t  get_time()
{
    struct timeval time;

    if (gettimeofday(&time, NULL) == -1)
        error(RED"gettimeofday: error\n"RESET, 1);
    return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void    free_all(t_free_all *gc, char *str, int out)
{
    int i;

    i = 0;
    while (i < gc->nb)
    {
        pthread_mutex_destroy(&gc->forks[i]);
        i++;
    }
    error(str, out);
}

void    print_philos(t_philo *philo, int num)
{
    int i;

    i = 0;
    while (i < num)
    {
        printf("%sNAME = %s%s\n%sNUM = %s%i\n%sBIRTH_TIME = %s%zu\n\n%s", RED, GREEN, philo[i].name, RED, GREEN, i + 1, RED, GREEN, philo[i].time.birth_time, RESET);
        i++;
    }
}

void    ft_usleep(size_t mls)
{
    size_t start;

    start = get_time();
    while (get_time() - start < mls)
        usleep(500);
}
