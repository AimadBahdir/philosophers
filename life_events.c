/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life_events.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abahdir <abahdir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 18:31:20 by abahdir           #+#    #+#             */
/*   Updated: 2021/07/12 14:54:41 by abahdir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_print_stat(short stat, t_philo *philo)
{
	if (philo->more->done)
		return ;
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
	pthread_mutex_unlock(&philo->more->print);
}

void	ft_eating(t_philo *philo)
{
	philo->last_eat = get_time();
	philo->is_eating = 1;
	pthread_mutex_lock(&philo->eating);
	philo->nb_eat++;
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
	ft_putstr("\x1B[0m");
	ft_putnbr(get_time() - philo->more->time_start);
	ft_putstr(" \x1b[37m[");
	ft_putnbr(philo->id);
	ft_putstr("]\x1B[0m ");
	ft_putstr("\x1b[31mdied\x1B[0m\n");
	return (1);
}
