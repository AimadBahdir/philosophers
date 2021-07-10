/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abahdir <abahdir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 08:02:23 by abahdir           #+#    #+#             */
/*   Updated: 2021/07/10 13:11:27 by abahdir          ###   ########.fr       */
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
	pthread_mutex_t	*forks;
	pthread_mutex_t	print;
	pthread_mutex_t	calc;
	size_t			nb_philos;
	size_t			nb_forks;
	size_t			tt_die;
	size_t			tt_eat;
	size_t			tt_sleep;
	size_t			nb_eat;
	long			time_start;
} t_args;

typedef struct s_philo
{
	size_t		id;
	pthread_t	th;
	size_t		nb_eat;
	int			last_eat;
	t_args		*more;
} t_philo;


short	check_errors(char	**inputs);
int		ft_strlen(char *str);
int		ft_atoi(const char *str);
void	ft_putnbr(long n);
void	ft_putstr(char *s);
void	set_args(int argc, char **argv, t_args **args);
void	*philo_life(void *arg);
void	ft_do(short stat, t_philo *philo);
void	*calc_tt_die(void *arg);
long		get_time(void);

#endif