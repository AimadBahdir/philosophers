/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abahdir <abahdir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 18:28:43 by abahdir           #+#    #+#             */
/*   Updated: 2021/07/11 11:01:08 by abahdir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

short	ft_puterror(char *err)
{
	if (err)
	{
		write(STDERR_FILENO, "\x1b[31m ERROR: ", ft_strlen("\x1b[31m ERROR: "));
		write(STDERR_FILENO, err, ft_strlen(err));
		write(STDERR_FILENO, "\x1b[0m\n", ft_strlen("\x1b[0m\n"));
	}
	return (1);
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

short	set_args(int argc, char **argv, t_args **args)
{
	int	i;

	(*args)->nb_philos = ft_atoi(argv[1]);
	(*args)->nb_forks = ft_atoi(argv[1]);
	(*args)->tt_die = ft_atoi(argv[2]);
	(*args)->tt_eat = ft_atoi(argv[3]);
	(*args)->tt_sleep = ft_atoi(argv[4]);
	(*args)->all_eat = 0;
	if (argc == 6)
		(*args)->nb_eat = ft_atoi(argv[5]);
	else
		(*args)->nb_eat = 0;
	(*args)->forks = malloc((*args)->nb_forks * sizeof(pthread_mutex_t));
	if (!(*args)->forks)
		return (ft_puterror("Bad allocation !"));
	i = -1;
	(*args)->time_start = get_time();
	while (++i < (int)(*args)->nb_philos)
		if (pthread_mutex_init(&(*args)->forks[i], NULL) != 0)
			return (ft_puterror("can't init a mutex!"));
	if (pthread_mutex_init(&(*args)->print, NULL) != 0)
		return (ft_puterror("can't init a mutex!"));
	return (0);
}
