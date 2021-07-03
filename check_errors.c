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
