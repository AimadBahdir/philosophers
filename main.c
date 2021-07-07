/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abahdir <abahdir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 17:57:16 by abahdir           #+#    #+#             */
/*   Updated: 2021/07/07 16:50:08 by abahdir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"





int main(int argc, char **argv)
{
	t_philo	*philos;
	t_args	*args;
	int		i;

	// if (argc > 4 && argc < 7 && check_errors(argv))
	// {
	// 	args = malloc(sizeof(*args));
	// 	set_args(argc, argv, &args);
	// 	philos = malloc(args->nb_philos * sizeof(t_philo));
	// 	i = -1;
	// 	while (++i < args->nb_philos)
	// 	{
	// 		philos[i].id = i + 1;
	// 		philos[i].nb_eat = 10/(i+1);
	// 		philos[i].last_eat = 0;
	// 		philos[i].more = args;
	// 		pthread_create(&philos[i].th, NULL, &philo_life, &philos[i]);
	// 	}
	// 	i = -1;
	// 	while (++i < args->nb_philos)
	// 		pthread_join(philos[i].th, NULL);
	// }
	// else
	// 	exit(write(STDOUT_FILENO, "Invalid inputs!\n", 16));
	return (0);
}