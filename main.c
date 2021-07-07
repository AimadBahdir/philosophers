/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abahdir <abahdir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 17:57:16 by abahdir           #+#    #+#             */
/*   Updated: 2021/07/03 19:56:32 by abahdir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	set_args(int argc, char **argv, t_args **args)
{
	int i;

	(*args)->nb_philos = ft_atoi(argv[1]);
	(*args)->nb_forks = ft_atoi(argv[1]);
	(*args)->tt_die = ft_atoi(argv[2]);
	(*args)->tt_eat = ft_atoi(argv[3]);
	(*args)->tt_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		(*args)->nb_eat = ft_atoi(argv[5]);
	else
		(*args)->nb_eat = 0;
	(*args)->forks = malloc((*args)->nb_forks * sizeof(pthread_mutex_t));
	i = -1;
	while (++i < (*args)->nb_philos)
		pthread_mutex_init(&(*args)->forks[i], NULL);
}

void	*philo_life(void *arg)
{
	t_philo	*philo;
	int		rf;
	int		lf;

	philo = (t_philo *)arg;
	lf = philo->id - 1;
	rf = philo->id % philo->more->nb_philos;
	pthread_mutex_lock(&philo->more->forks[lf]);
	pthread_mutex_lock(&philo->more->forks[rf]);
	printf("Hi, my id is: %zu\n", philo->id);
	printf("I'm eat %zu times\n", philo->nb_eat);
	// usleep(5000000);
	pthread_mutex_unlock(&philo->more->forks[lf]);
	pthread_mutex_unlock(&philo->more->forks[rf]);
	return (philo);
}

int main(int argc, char **argv)
{
	t_philo	*philos;
	t_args	*args;
	int		i;

	if (argc > 4 && argc < 7 && check_errors(argv))
	{
		args = malloc(sizeof(*args));
		set_args(argc, argv, &args);
		philos = malloc(args->nb_philos * sizeof(t_philo));
		i = -1;
		while (++i < args->nb_philos)
		{
			philos[i].id = i + 1;
			philos[i].nb_eat = 10/(i+1);
			philos[i].last_eat = 0;
			philos[i].more = args;
			pthread_create(&philos[i].th, NULL, &philo_life, &philos[i]);
		}
		i = -1;
		while (++i < args->nb_philos)
			pthread_join(philos[i].th, NULL);
	}
	else
		exit(write(STDOUT_FILENO, "Invalid inputs!\n", 16));
	return (0);
}