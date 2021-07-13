/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life_events.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abahdir <abahdir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 18:31:20 by abahdir           #+#    #+#             */
/*   Updated: 2021/07/13 13:41:43 by abahdir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_print_stat(short stat, t_philo *philo)
{
	if (philo->more->done)
		return ;
	pthread_mutex_lock(&philo->more->print);
	if (stat == 1)
		printf("\x1b[34m%ld %d has taken a fork\x1B[0m\n",
			get_time() - philo->more->time_start, philo->id);
	else if (stat == 2)
		printf("\x1b[32m%ld %d is eating\x1B[0m\n",
			get_time() - philo->more->time_start, philo->id);
	else if (stat == 3)
		printf("\x1b[33m%ld %d is thinking\x1B[0m\n",
			get_time() - philo->more->time_start, philo->id);
	else if (stat == 4)
		printf("\x1b[36m%ld %d is sleeping\x1B[0m\n",
			get_time() - philo->more->time_start, philo->id);
	pthread_mutex_unlock(&philo->more->print);
}

void	ft_eating(t_philo *philo)
{
	philo->is_eating = 1;
	philo->last_eat = get_time();
	pthread_mutex_lock(&philo->eating);
	philo->nb_eat += 1;
	if (philo->nb_eat == philo->more->nb_eat)
		 philo->more->all_eat += 1;
	ft_print_stat(2, philo);
	ft_pause(philo->more->tt_eat);
	pthread_mutex_unlock(&philo->eating);
	philo->is_eating = 0;
}

void	ft_sleeping(t_philo *philo)
{
	ft_print_stat(4, philo);
	ft_pause(philo->more->tt_sleep);
}

short	ft_died(t_philo *philo)
{
	pthread_mutex_lock(&philo->more->print);
	printf("\x1b[31m%ld %d died\x1B[0m\n",
		get_time() - philo->more->time_start, philo->id);
	pthread_mutex_unlock(&philo->eating);
	return (1);
}
