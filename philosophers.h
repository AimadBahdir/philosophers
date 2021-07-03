/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abahdir <abahdir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 08:02:23 by abahdir           #+#    #+#             */
/*   Updated: 2021/07/03 19:44:50 by abahdir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <pthread.h>

typedef struct s_args 
{
	size_t	nb_philos;
	size_t	nb_forks;
	size_t	tt_die;
	size_t	tt_eat;
	size_t	tt_sleep;
	size_t	nb_eat;
} t_args;

typedef struct s_philo
{
	pthread_t		id;
	pthread_mutex_t	fork;
	size_t			nb_eat;
	size_t			last_eat;
	t_args			*arg;
} t_philo;


short	check_errors(char	**inputs);
int		ft_strlen(char *str);
int		ft_atoi(const char *str);
void	set_args(int argc, char **argv, t_args **args);

#endif