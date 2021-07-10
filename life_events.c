/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life_events.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abahdir <abahdir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 18:31:20 by abahdir           #+#    #+#             */
/*   Updated: 2021/07/10 17:39:11 by abahdir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_print_stat(short stat, t_philo *philo)
{
	pthread_mutex_lock(&philo->more->print);
	ft_putstr("\x1B[0m");
	ft_putnbr(get_time() - philo->more->time_start);
	ft_putstr(" \x1b[37m[");
	ft_putnbr(philo->id);
	ft_putstr("]\x1B[0m ");
	if (stat == 1)
		ft_putstr("\x1b[34mhas taken a fork\x1B[0m\n");
	else if (stat == 2)
		ft_putstr("\x1b[32mis eating\x1B[0m\n");
	else if (stat == 3)
		ft_putstr("\x1b[33mis thinking\x1B[0m\n");
	else if (stat == 4)
		ft_putstr("\x1b[36mis sleeping\x1B[0m\n");
	else if (stat == 5)
		ft_putstr("\x1b[31mdied\x1B[0m\n");
	if (stat != 5)
		pthread_mutex_unlock(&philo->more->print);
}

void	ft_eating(t_philo *philo)
{
	philo->eating = 1;
	if (++philo->nb_eat == philo->more->nb_eat)
		 philo->more->all_eat += 1;
	ft_print_stat(2, philo);
	philo->last_eat = get_time();
	ft_pause(philo->more->tt_eat);
	philo->eating = 0;
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
