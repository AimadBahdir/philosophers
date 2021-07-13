/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_time.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abahdir <abahdir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 14:50:57 by abahdir           #+#    #+#             */
/*   Updated: 2021/07/12 17:20:41 by abahdir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_pause(long time)
{
	long	time_now;

	time_now = get_time();
	usleep((time * 1000) - 20000);
	while (get_time() - time_now < time)
		 ;
}

long	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}
