/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abahdir <abahdir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 08:02:23 by abahdir           #+#    #+#             */
/*   Updated: 2021/07/08 17:38:45 by abahdir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_args 
{
	struct timeval	time;
	pthread_mutex_t	*forks;
	pthread_mutex_t	w_protect;
	size_t			nb_philos;
	size_t			nb_forks;
	size_t			tt_die;
	size_t			tt_eat;
	size_t			tt_sleep;
	size_t			nb_eat;
} t_args;

typedef struct s_philo
{
	size_t		id;
	pthread_t	th;
	size_t		nb_eat;
	size_t		last_eat;
	t_args		*more;
} t_philo;


short	check_errors(char	**inputs);
int		ft_strlen(char *str);
int		ft_atoi(const char *str);
void	ft_putnbr(int n, char *color);
void	ft_putstr(char *s, char *color);
void	set_args(int argc, char **argv, t_args **args);
void	*philo_life(void *arg);
void	fork_taken(t_philo *philo);
void	eating(t_philo *philo);
void	thinking(t_philo *philo);
void	sleeping(t_philo *philo);
void	died(t_philo *philo);

#endif