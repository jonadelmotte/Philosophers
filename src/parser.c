/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelmott <jdelmott@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 17:10:41 by jdelmott          #+#    #+#             */
/*   Updated: 2026/05/15 11:11:23 by jdelmott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

int	is_num(char *arg)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		if (arg[i] < '0' || arg[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

long int	ft_atoi(const char *str)
{
	int			i;
	long int	retu;

	retu = 0;
	i = -1;
	while (str[++i])
		retu = (retu * 10) + (str[i] - '0');
	return (retu);
}

int	parser(char **arg, int argc, t_pars *pars)
{
	int	i;

	i = 0;
	while (arg[++i])
	{
		if (!is_num(arg[i]))
			return (1);
	}
	pars->nb_philo = ft_atoi(arg[1]);
	pars->nb_fork = ft_atoi(arg[1]);
	pars->t_die = ft_atoi(arg[2]);
	pars->t_eat = ft_atoi(arg[3]);
	pars->t_sleep = ft_atoi(arg[4]);
	if (pars->nb_fork < 1 || pars->t_die < 0 || pars->t_eat < 0
		|| pars->t_sleep < 0 || pars->nb_fork > INT_MAX || pars->t_die > INT_MAX
		|| pars->t_eat > INT_MAX || pars->t_sleep > INT_MAX)
		return (1);
	if (argc == 6)
	{
		pars->num_eat = ft_atoi(arg[5]);
		if (pars->num_eat < 0 || pars->num_eat > INT_MAX)
			return (1);
	}
	else
		pars->num_eat = -1;
	return (0);
}
