/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abahdir <abahdir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 17:57:16 by abahdir           #+#    #+#             */
/*   Updated: 2021/07/12 15:08:57 by abahdir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

short	ft_creat_philo(t_philo *philos, int index, t_args *args)
{
	philos[index].id = index + 1;
	philos[index].nb_eat = 0;
	philos[index].last_eat = get_time();
	philos[index].lfork = 0;
	philos[index].rfork = 0;
	philos[index].more = args;
	philos[index].is_eating = 0;
	if (pthread_mutex_init(&philos[index].eating, NULL) != 0)
		return (ft_puterror("can't init a mutex!"));
	if (pthread_create(&philos[index].th, NULL,
			&philo_life, &philos[index]) != 0)
		return (ft_puterror("can't creat a thread!"));
	return (0);
}

int	ft_death(t_philo *philo, t_args *args, int tt_die)
{
	if (tt_die > (int)args->tt_die)
	{
		if (philo->lfork)
		{
			pthread_mutex_unlock(&args->forks[philo->id - 1]);
			philo->lfork--;
		}
		if (philo->rfork)
		{
			pthread_mutex_unlock(&args->forks[philo->id % args->nb_philos]);
			philo->rfork--;
		}
		args->done = 1;
		return (1);
	}
	return (0);
}

short	ft_check_die(t_philo *philos, t_args *args)
{
	int	i;

	while (!args->done)
	{
		i = -1;
		while (++i < (int)args->nb_philos)
		{
			if (!philos[i].is_eating)
			{
				pthread_mutex_lock(&philos[i].eating);
				if (ft_death(&philos[i], args, get_time() - philos[i].last_eat))
					return (ft_died(&philos[i]));
				pthread_mutex_unlock(&philos[i].eating);
			}
		}
		usleep(800);
		if (args->nb_philos == args->all_eat)
			args->done = 1;
	}
	return (0);
}

short	ft_run(t_philo *philos, t_args *args)
{
	int	i;

	i = 0;
	while (i < (int)args->nb_philos)
	{
		if (ft_creat_philo(philos, i, args))
			return (1);
		i += 2;
	}
	usleep(1000);
	i = 1;
	while (i < (int)args->nb_philos)
	{
		if (ft_creat_philo(philos, i, args))
			return (1);
		i += 2;
	}
	return (ft_check_die(philos, args));
}

int	main(int argc, char **argv)
{
	t_philo	*philos;
	t_args	*args;
	int		err;

	philos = NULL;
	args = NULL;
	if (argc > 4 && argc < 7 && check_errors(argv))
	{
		args = malloc(sizeof(*args));
		if (!args)
			return (ft_puterror("Bad allocation !"));
		if (set_args(argc, argv, &args))
			return (1);
		pthread_mutex_lock(&args->free);
		philos = malloc(args->nb_philos * sizeof(t_philo));
		if (!philos)
			return (ft_puterror("Bad allocation !"));
		err = ft_run(philos, args);
		return (refree(philos, args, err));
	}
	else
		return (ft_puterror("Invalid inputs!"));
	return (0);
}
