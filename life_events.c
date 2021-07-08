/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life_events.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abahdir <abahdir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 18:31:20 by abahdir           #+#    #+#             */
/*   Updated: 2021/07/08 17:47:25 by abahdir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	fork_taken(t_philo *philo)
{
	pthread_mutex_lock(&philo->more->w_protect);
	gettimeofday(&philo->more->time, NULL);
	ft_putnbr(philo->more->time.tv_usec * 1000, "\033[1;m");
	ft_putstr(" ", NULL);
	ft_putnbr(philo->id, "\033[1;m");
	ft_putstr(" has taken a fork\n", "\033[1;32m");
	pthread_mutex_unlock(&philo->more->w_protect);
}

void	eating(t_philo *philo)
{
	pthread_mutex_lock(&philo->more->w_protect);
	gettimeofday(&philo->more->time, NULL);
	ft_putnbr(philo->more->time.tv_usec * 1000, "\033[1;m");
	ft_putstr(" ", NULL);
	ft_putnbr(philo->id, "\033[1;m");
	ft_putstr(" is eating\n", "\033[1;32m");
	usleep(philo->more->tt_eat * 1000);
	philo->nb_eat++;
	pthread_mutex_unlock(&philo->more->w_protect);
}

void	thinking(t_philo *philo)
{
	pthread_mutex_lock(&philo->more->w_protect);
	ft_putnbr(philo->more->time.tv_usec * 1000, "\033[1;m");
	ft_putstr(" ", NULL);
	ft_putnbr(philo->id, "\033[1;m");
	ft_putstr(" is thinking\n", "\033[1;33m");
	pthread_mutex_unlock(&philo->more->w_protect);
}

void	sleeping(t_philo *philo)
{
	pthread_mutex_lock(&philo->more->w_protect);
	ft_putnbr(philo->more->time.tv_usec * 1000, "\033[1;m");
	ft_putstr(" ", NULL);
	ft_putnbr(philo->id, "\033[1;m");
	ft_putstr(" is sleeping\n", "\033[1;34m");
	usleep(philo->more->tt_sleep * 1000);
	pthread_mutex_unlock(&philo->more->w_protect);
}

void	died(t_philo *philo)
{
	pthread_mutex_lock(&philo->more->w_protect);
	ft_putnbr(philo->more->time.tv_usec * 1000, "\033[1;m");
	ft_putstr(" ", NULL);
	ft_putnbr(philo->id, "\033[1;m");
	ft_putstr(" died\n", "\033[1;31m");
	pthread_mutex_unlock(&philo->more->w_protect);
}
