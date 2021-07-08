/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life_cycle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abahdir <abahdir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 16:14:27 by abahdir           #+#    #+#             */
/*   Updated: 2021/07/08 17:51:10 by abahdir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*calc_tt_die(void *arg)
{
	
	return (NULL);
}

void	*philo_life(void *arg)
{
	t_philo	*philo;
	int		rf;
	int		lf;

	philo = (t_philo *)arg;
	lf = philo->id - 1;
	rf = philo->id % philo->more->nb_philos;
	while (1)
	{
		pthread_mutex_lock(&philo->more->forks[lf]);
		pthread_mutex_lock(&philo->more->forks[rf]);
		fork_taken(philo);
		eating(philo);
		pthread_mutex_unlock(&philo->more->forks[lf]);
		pthread_mutex_unlock(&philo->more->forks[rf]);
		sleeping(philo);
		thinking(philo);
	}
	
	return (philo);
}
