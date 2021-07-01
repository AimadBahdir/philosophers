/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abahdir <abahdir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 17:57:16 by abahdir           #+#    #+#             */
/*   Updated: 2021/07/01 09:48:43 by abahdir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

short   check_errors(char **inputs)
{
	
	return (0);
}

int main(int argc, char **argv)
{

	t_philo **philos;

	philos = malloc(5 * sizeof(t_philo *));
	philos[6] = malloc(sizeof(t_philo));
	philos[6]->nb_eat = 15;
	printf("NBEAT : %zu\n", philos[6]->nb_eat);
	return (0);
}