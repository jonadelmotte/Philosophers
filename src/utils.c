#include "../include/philosophers.h"

size_t ft_strlen(char *str)
{
    size_t i;

    i = 0;
    while (str[i])
        i++;
    return (i);
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