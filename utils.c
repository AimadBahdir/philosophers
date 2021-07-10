/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abahdir <abahdir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 18:13:05 by abahdir           #+#    #+#             */
/*   Updated: 2021/07/10 12:50:57 by abahdir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	getsign(const char *str, int *i)
{
	if (str[*i] == '-')
	{
		*i += 1;
		return (-1);
	}
	else if (str[*i] == '+')
	{
		*i += 1;
		return (1);
	}
	return (1);
}

int	ft_atoi(const char *str)
{
	int		i;
	int		sign;
	long	result;

	i = 0;
	result = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	sign = getsign(str, &i);
	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
			result = result * 10 + (str[i] - '0');
		i++;
	}
	if ((result > 2147483648 && sign == -1)
		|| (result > 2147483647 && sign == 1))
		exit(write(STDOUT_FILENO, "Inputs is too long!\n", 20));
	return (result * sign);
}

void	ft_putnbr(long n)
{
	int		sign;
	char	c;
	long	nn;

	sign = 1;
	nn = n;
	if (nn < 0)
	{
		sign = -1;
		nn *= sign;
		write(STDOUT_FILENO, "-", 1);
	}
	if (nn >= 10)
	{
		ft_putnbr(nn / 10);
		ft_putnbr(nn % 10);
	}
	else
	{
		c = nn % 10 + 48;
		write(STDOUT_FILENO, &c, 1);
	}
}

void	ft_putstr(char *s)
{
	if (s != NULL)
		write(STDOUT_FILENO, s, ft_strlen(s));
}
