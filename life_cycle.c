/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life_cycle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abahdir <abahdir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 16:14:27 by abahdir           #+#    #+#             */
/*   Updated: 2021/07/07 16:24:06 by abahdir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	fork_taken(t_philo *philo)
{
	write(STDOUT_FILENO, "has taken a fork\n", 17);
}

void	eating(t_philo *philo)
{
	write(STDOUT_FILENO, "eating\n", 7);
}

void	thinking(t_philo *philo)
{
	write(STDOUT_FILENO, "thinking\n", 9);
}

void	sleeping(t_philo *philo)
{
	write(STDOUT_FILENO, "sleeping\n", 9);
}

void	died(t_philo *philo)
{
	write(STDOUT_FILENO, "died\n", 5);
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
