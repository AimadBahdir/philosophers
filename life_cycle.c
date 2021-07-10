/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life_cycle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abahdir <abahdir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 16:14:27 by abahdir           #+#    #+#             */
/*   Updated: 2021/07/10 15:30:41 by abahdir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*philo_life(void *arg)
{
	t_philo		*philo;
	pthread_t	calc;
	int			rf;
	int			lf;

	philo = (t_philo *)arg;
	lf = philo->id - 1;
	rf = philo->id % philo->more->nb_philos;
	while (1)
	{
		pthread_mutex_lock(&philo->more->forks[lf]);
		ft_print_stat(1, philo);
		pthread_mutex_lock(&philo->more->forks[rf]);
		ft_print_stat(1, philo);
		ft_eating(philo);
		pthread_mutex_unlock(&philo->more->forks[lf]);
		pthread_mutex_unlock(&philo->more->forks[rf]);
		ft_sleeping(philo);
		ft_print_stat(3, philo);
	}
	
	return (philo);
}
