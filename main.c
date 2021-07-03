/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abahdir <abahdir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 17:57:16 by abahdir           #+#    #+#             */
/*   Updated: 2021/07/03 19:56:32 by abahdir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	set_args(int argc, char **argv, t_args **args)
{
	(*args)->nb_philos = ft_atoi(argv[1]);
	(*args)->nb_forks = ft_atoi(argv[1]);
	(*args)->tt_die = ft_atoi(argv[2]);
	(*args)->tt_eat = ft_atoi(argv[3]);
	(*args)->tt_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		(*args)->nb_eat = ft_atoi(argv[5]);
	else
		(*args)->nb_eat = 0;
}

int main(int argc, char **argv)
{
	t_philo	**philos;
	t_args	*args;

	if (argc > 4 && argc < 7 && check_errors(argv))
	{
		args = malloc(sizeof(t_args *));
		set_args(argc, argv, &args);
		// philos = malloc(args->nb_philos * sizeof(t_philo *));
		printf("INUTS: %zu, %zu, %zu, %zu, %zu, %zu\n", args->nb_philos, args->nb_forks, args->tt_die, args->tt_eat, args->tt_sleep, args->nb_eat);
	}
	else
		exit(write(STDOUT_FILENO, "Invalid inputs!\n", 16));
	return (0);
}