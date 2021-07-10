/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abahdir <abahdir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 17:57:16 by abahdir           #+#    #+#             */
/*   Updated: 2021/07/10 19:30:09 by abahdir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

short	ft_creat_philo(t_philo *philos, int index, t_args *args)
{
	philos[index].id = index + 1;
	philos[index].nb_eat = 0;
	philos[index].last_eat = get_time();
	philos[index].eating = 0;
	philos[index].more = args;
	if (pthread_create(&philos[index].th, NULL, &philo_life, &philos[index]) != 0)
		return (ft_puterror("can't creat a thread!"));
	return (0);
}

short	ft_check_die(t_philo *philos, t_args *args)
{
	int	i;
	int	tt_die;

	while (1)
	{
		i = 0;
		while (i < (int)args->nb_philos)
		{
			tt_die = get_time() - philos[i].last_eat;
			if (tt_die > (int)args->tt_die && !philos[i].eating)
				return(ft_died(&philos[i]));
			i++;
		}
		if (args->nb_philos == args->all_eat)
			return(1);
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

int main(int argc, char **argv)
{
	t_philo	*philos;
	t_args	*args;

	if (argc > 4 && argc < 7 && check_errors(argv))
	{
		args = malloc(sizeof(*args));
		if (!args)
			return (ft_puterror("Bad allocation !"));
		set_args(argc, argv, &args);
		philos = malloc(args->nb_philos * sizeof(t_philo));
		if (!philos)
			return (ft_puterror("Bad allocation !"));
		return (ft_run(philos, args));
	}
	else
		return(ft_puterror("Invalid inputs!"));
	return (0);
}