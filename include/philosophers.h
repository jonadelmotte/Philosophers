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

/* * * * * * * PARSER * * * * * * * */
int		is_num(char *arg);
long int		ft_atoi(const char *str);
int		parser(char **arg, int argc, t_pars *pars);

#endif