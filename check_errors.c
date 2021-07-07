/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abahdir <abahdir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 18:28:43 by abahdir           #+#    #+#             */
/*   Updated: 2021/07/03 19:38:45 by abahdir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

short	check_errors(char	**inputs)
{
	int		i;
	int		j;

	i = 0;
	while (inputs[++i])
	{
		j = -1;
		while (inputs[i][++j])
		{
			if (inputs[i][j] < '0' || inputs[i][j] > '9')
				return (0);
		}
	}
	return (1);
}

void	set_args(int argc, char **argv, t_args **args)
{
	int i;

	(*args)->nb_philos = ft_atoi(argv[1]);
	(*args)->nb_forks = ft_atoi(argv[1]);
	(*args)->tt_die = ft_atoi(argv[2]);
	(*args)->tt_eat = ft_atoi(argv[3]);
	(*args)->tt_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		(*args)->nb_eat = ft_atoi(argv[5]);
	else
		(*args)->nb_eat = 0;
	(*args)->forks = malloc((*args)->nb_forks * sizeof(pthread_mutex_t));
	i = -1;
	while (++i < (*args)->nb_philos)
		pthread_mutex_init(&(*args)->forks[i], NULL);
}
