/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelmott <jdelmott@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 17:11:17 by jdelmott          #+#    #+#             */
/*   Updated: 2026/05/07 17:11:18 by jdelmott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>
# include <time.h>

# define RESET	"\e[0m"
# define RED	"\e[31m"
# define GREEN	"\e[32m"

# define INT_MAX 2147483647

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
	// char	*name;
	t_time time;
	pthread_t	thread_id;
	int		eat_objct;
	int		eat_count;
}		t_philo;

/* * * * * * * PARSER * * * * * * * */
int		is_num(char *arg);
long int		ft_atoi(const char *str);
int		parser(char **arg, int argc, t_pars *pars);
void    init_philos(t_pars pars, t_philo *philo);

/* * * * * * * * UTILS * * * * * * * */
size_t ft_strlen(char *str);
void    error(char *str, int out);
size_t	get_time();

#endif