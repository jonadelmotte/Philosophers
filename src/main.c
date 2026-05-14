/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelmott <jdelmott@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 17:10:17 by jdelmott          #+#    #+#             */
/*   Updated: 2026/05/11 17:43:48 by jdelmott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

int	main(int argc, char *argv[])
{
	t_pars	pars;
	t_philo *philo;

	if (argc > 6 || argc < 5)
		error(RED"Not the right amount of args\n"RESET, 1);
	if (parser(argv, argc, &pars))
		error(RED"invalid args\n"RESET, 1);
	printf("%snb_philo = %li, nb_fork = %li, t_die = %li, t_eat = %li, t_sleep = %li, num_eat = %li\n%s", GREEN, pars.nb_philo, pars.nb_fork, pars.t_die, pars.t_eat, pars.t_sleep, pars.num_eat, RESET);
	philo = malloc(sizeof(t_philo) * pars.nb_philo);
	if (!philo)
		error(RED"malloc: error\n"RESET, 1);
	init_philos(pars, philo);
	printf("%sbirth_time = %zu\n%s", RED, philo[0].time.birth_time, RESET);
}
