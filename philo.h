/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abahdir <abahdir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 08:02:23 by abahdir           #+#    #+#             */
/*   Updated: 2021/07/12 17:21:07 by abahdir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
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
	pthread_mutex_t	free;
	int				nb_philos;
	int				nb_forks;
	int				tt_die;
	int				tt_eat;
	int				tt_sleep;
	int				nb_eat;
	int				all_eat;
	short			done;
	long			time_start;
}				t_args;

typedef struct s_philo
{
	int				id;
	pthread_t		th;
	int				nb_eat;
	int				last_eat;
	short			lfork;
	short			rfork;
	short			is_eating;
	pthread_mutex_t	eating;
	t_args			*more;
}				t_philo;

short	check_errors(char **inputs);
int		ft_strlen(char *str);
int		ft_atoi(const char *str);
void	ft_putnbr(long n);
void	ft_putstr(char *s);
short	ft_puterror(char *err);
short	set_args(int argc, char **argv, t_args **args);
short	ft_creat_philo(t_philo *philos, int index, t_args *args);
short	ft_run(t_philo *philos, t_args *args);
void	*philo_life(void *arg);
void	ft_sleeping(t_philo *philo);
void	ft_eating(t_philo *philo);
void	ft_print_stat(short stat, t_philo *philo);
short	ft_check_die(t_philo *philos, t_args *args);
long	get_time(void);
void	ft_pause(long time);
short	ft_died(t_philo *philo);
int		refree(t_philo *philos, t_args *args, int ret);

#endif