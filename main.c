/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abahdir <abahdir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 17:57:16 by abahdir           #+#    #+#             */
/*   Updated: 2021/07/10 13:24:44 by abahdir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_creat_philo(t_philo *philos, int index, t_args *args)
{
	philos[index].id = index + 1;
	philos[index].nb_eat = 0;
	philos[index].last_eat = get_time();
	philos[index].more = args;
	if (pthread_create(&philos[index].th, NULL, &philo_life, &philos[index]) != 0)
		exit(1);
}

void	ft_run(t_philo *philos, t_args *args)
{
	int		i;

	i = 0;
	while (i < args->nb_philos)
	{
		ft_creat_philo(philos, i, args);
		i +=2;
	}
	usleep(1000);
	i = 1;
	while (i < args->nb_philos)
	{
		ft_creat_philo(philos, i, args);
		i +=2;
	}
	i = -1;
	while (++i < args->nb_philos)
		pthread_join(philos[i].th, NULL);
}

int main(int argc, char **argv)
{
	t_philo	*philos;
	t_args	*args;

	if (argc > 4 && argc < 7 && check_errors(argv))
	{
		args = malloc(sizeof(*args));
		set_args(argc, argv, &args);
		philos = malloc(args->nb_philos * sizeof(t_philo));
		ft_run(philos, args);
	}
	else
		exit(write(STDOUT_FILENO, "Invalid inputs!\n", 16));
	return (0);
}