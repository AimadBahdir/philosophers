/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abahdir <abahdir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 08:02:23 by abahdir           #+#    #+#             */
/*   Updated: 2021/06/30 18:56:30 by abahdir          ###   ########.fr       */
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
} t_args;

typedef struct s_philo
{
	pthread_t	id;
	size_t		nb_eat;
	t_args		*arg;
} t_philo;

#endif