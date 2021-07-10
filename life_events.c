/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life_events.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abahdir <abahdir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 18:31:20 by abahdir           #+#    #+#             */
/*   Updated: 2021/07/10 15:22:06 by abahdir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_print_stat(short stat, t_philo *philo)
{
	pthread_mutex_lock(&philo->more->print);
	ft_putstr("\x1B[0m");
	ft_putnbr(get_time() - philo->more->time_start);
	ft_putstr(" ");
	ft_putnbr(philo->id);
	if (stat == 1)
		ft_putstr("\x1B[31m has taken a fork\x1B[0m\n");
	else if (stat == 2)
		ft_putstr("\x1B[32m is eating\x1B[0m\n");
	else if (stat == 3)
		ft_putstr("\x1B[33m is thinking\x1B[0m\n");
	else if (stat == 4)
		ft_putstr("\x1B[34m is sleeping\x1B[0m\n");
	else if (stat == 5)
		ft_putstr("\x1B[35m died\x1B[0m\n");
	if (stat != 5)
		pthread_mutex_unlock(&philo->more->print);
}

void	ft_eating(t_philo *philo)
{
	ft_print_stat(2, philo);
	philo->nb_eat++;
	ft_pause(philo->more->tt_eat);
	philo->last_eat = get_time();
}

void	ft_sleeping(t_philo *philo)
{
	ft_print_stat(4, philo);
	ft_pause(philo->more->tt_sleep);
}

void	ft_died(t_philo *philo)
{
	ft_print_stat(5, philo);
	exit(0);
}
