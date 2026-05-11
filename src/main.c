/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelmott <jdelmott@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 17:10:17 by jdelmott          #+#    #+#             */
/*   Updated: 2026/05/07 17:10:35 by jdelmott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

int	main(int argc, char *argv[])
{
	t_pars	pars;

	if (argc > 6 || argc < 5)
		return (printf("Not the right amount of args\n"), 1);
	if (parser(argv, argc, &pars))
		return (printf("Invalide args\n"), 1);
	printf("\e[1;34mnb_philo = %i, nb_fork = %i, t_die = %i, t_eat = %i, t_sleep = %i, num_eat = %i\n$", pars.nb_philo, pars.nb_fork, pars.t_die, pars.t_eat, pars.t_sleep, pars.num_eat);
}
