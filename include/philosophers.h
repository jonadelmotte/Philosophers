/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelmott <jdelmott@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 17:11:17 by jdelmott          #+#    #+#             */
/*   Updated: 2026/05/15 15:45:42 by jdelmott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>
# include <time.h>
# include "philo_library.h"

# define RESET	"\e[0m"
# define RED	"\e[31m"
# define GREEN	"\e[32m"

// # define INT_MAX 2147483647

typedef pthread_mutex_t	t_mutex;

typedef struct s_pars
{
	long int	nb_philo;
	long int	nb_fork;
	long int	t_die;
	long int	t_eat;
	long int	t_sleep;
	long int	num_eat;
}		t_pars;

typedef struct s_time
{
	size_t	die;
	size_t eat;
	size_t	sleep;
	size_t prev_eat;
	size_t	birth_time;
}		t_time;

typedef struct s_philo
{
	int		index;
	char	name[MAX_LEN];
	t_time time;
	pthread_t	thread_id;
	int		eat_objct;
	int		eat_count;
	t_mutex *left_fork;
	t_mutex *right_fork;
}		t_philo;

typedef struct s_free_all
{
	int		nb;
	t_mutex *forks;
	t_philo *philos;
}		t_free_all;

/* * * * * * * PARSER * * * * * * * */
int		is_num(char *arg);
long int		ft_atoi(const char *str);
int		parser(char **arg, int argc, t_pars *pars);

/* * * * * PHILO NAME * * * * * * * * */
char    *find_philo(size_t id);
const char    *philo_name(size_t id);

/* * * * * * * * INIT * * * * * * * * */
void    init_philos(t_pars pars, t_philo *philo, t_mutex *forks);
void    init_forks(t_free_all gc, t_pars pars, t_mutex *forks);
void    print_philos(t_philo *philo, int num);
void    init_gc(t_free_all *gc, t_mutex *fork, t_philo *philos, t_pars parser);

/* * * * * * * * ALGO * * * * * * * * * */
void    init_table(t_free_all *gc);

/* * * * * * * * UTILS * * * * * * * */
size_t ft_strlen(char *str);
void    error(char *str, int out);
void    free_all(t_free_all *gc, char *str, int out);
size_t	get_time();
void    free_fork(char *str, int out, t_mutex **fork, int num);
size_t	ft_strcpy(char *dest, const char *src);
void    ft_usleep(size_t mls);

#endif