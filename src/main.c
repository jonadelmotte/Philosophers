/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelmott <jdelmott@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 17:10:17 by jdelmott          #+#    #+#             */
/*   Updated: 2026/05/15 11:12:49 by jdelmott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

int	main(int argc, char *argv[])
{
	t_pars	pars;
	t_philo *philo;
	// t_mutex	*forks;

	if (argc > 6 || argc < 5)
		error(RED"Not the right amount of args\n"RESET, 1);
	if (parser(argv, argc, &pars))
		error(RED"invalid args\n"RESET, 1);
	philo = malloc(sizeof(t_philo) * (pars.nb_philo + 1));
	if (!philo)
		error(RED"malloc: error\n"RESET, 1);
	// forks = malloc(sizeof(t_philo) * (pars.nb_fork + 1));
	// if (!forks)
	// 	error(RED"malloc: error\n"RESET, 1);// GERE LES MALLOC JONA
	init_philos(pars, philo);
	// init_forks(pars, &forks);
	print_philos(philo, pars.nb_philo);
}
