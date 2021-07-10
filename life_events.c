/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life_events.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abahdir <abahdir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 18:31:20 by abahdir           #+#    #+#             */
/*   Updated: 2021/07/10 13:11:04 by abahdir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_pause(int time)
{
	usleep(time);
}

long	get_time(void)
{
	struct timeval time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void	ft_do(short stat, t_philo *philo)
{
	ft_putstr("\x1B[0m");
	ft_putnbr(get_time());
	ft_putstr(" ");
	ft_putnbr(philo->id);
	pthread_mutex_lock(&philo->more->print);
	if (stat == 1)
		ft_putstr("\x1B[31mis has taken a fork\n\x1B[0m");
	else if (stat == 2)
	{
		philo->last_eat = get_time();
		ft_putstr("\x1B[32mis is eating\n\x1B[0m");
		philo->nb_eat++;
		ft_pause(philo->more->tt_eat);
	}
	else if (stat == 3)
		ft_putstr("\x1B[33mis is thinking\n\x1B[0m");
	else if (stat == 4)
	{
		ft_putstr("\x1B[34mis is sleeping\n\x1B[0m");
		ft_pause(philo->more->tt_sleep);
	}
	pthread_mutex_unlock(&philo->more->print);
}
