/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life_cycle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abahdir <abahdir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 16:14:27 by abahdir           #+#    #+#             */
/*   Updated: 2021/07/10 13:10:23 by abahdir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*calc_tt_die(void *arg)
{
	t_philo	*philo;
	int		tt_die;
	

	philo = (t_philo *)arg;
	tt_die = get_time() - philo->last_eat;

	pthread_mutex_lock(&philo->more->print);
	// ft_putnbr(tt_die, NULL);
	// ft_putstr("\n", NULL);
	pthread_mutex_unlock(&philo->more->print);
	// if (tt_die > philo->more->tt_die)
	// 	died(philo);
	return (NULL);
}

void	*philo_life(void *arg)
{
	t_philo		*philo;
	pthread_t	calc;
	int			rf;
	int			lf;

	philo = (t_philo *)arg;
	lf = philo->id - 1;
	rf = philo->id % philo->more->nb_philos;
	if (pthread_create(&calc, NULL, &calc_tt_die, &philo) != 0)
		exit(1);
	while (1)
	{
		pthread_mutex_lock(&philo->more->forks[lf]);
		fork_taken(1, philo);
		pthread_mutex_lock(&philo->more->forks[rf]);
		fork_taken(1, philo);
		eating(2, philo);
		pthread_mutex_unlock(&philo->more->forks[lf]);
		pthread_mutex_unlock(&philo->more->forks[rf]);
		sleeping(4, philo);
		thinking(3, philo);
	}
	
	return (philo);
}
