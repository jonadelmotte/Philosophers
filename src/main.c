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
	t_philo philo[200];
	t_mutex	forks[200];
	t_free_all gc;

	if (argc > 6 || argc < 5)
		error(RED"Not the right amount of args\n"RESET, 1);
	if (parser(argv, argc, &pars))
		error(RED"invalid args\n"RESET, 1);
	init_gc(&gc, forks, philo, pars);
	init_philos(pars, philo, forks);
	init_forks(gc, pars, forks);
	print_philos(philo, pars.nb_philo);
	free_all(&gc, GREEN"everything is good and well\n"RESET, 0);
}
