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

typedef struct s_pars
{
	int	nb_philo;
	int	nb_fork;
	int	t_die;
	int	t_eat;
	int	t_sleep;
	int	num_eat;
}		t_pars;

/* * * * * * * PARSER * * * * * * * */
int		is_num(char *arg);
int		ft_atoi(const char *str);
int		parser(char **arg, int argc, t_pars *pars);

#endif