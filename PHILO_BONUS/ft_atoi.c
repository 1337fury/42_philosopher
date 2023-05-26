/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdeel-o < abdeel-o@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 19:44:04 by abdeel-o          #+#    #+#             */
/*   Updated: 2023/05/13 16:24:09 by abdeel-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static int	skiper(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && (str[i] == ' '
			|| str[i] == '\n'
			|| str[i] == '\f'
			|| str[i] == '\r'
			|| str[i] == '\t'
			|| str[i] == '\v'))
		i++;
	return (i);
}

int	ft_atoi(const char *str)
{
	int				i;
	int				n;
	int				res;

	res = 0;
	n = 1;
	i = skiper(str);
	if (!str[i])
		return (-2);
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			n = -n;
		i++;
	}
	if (str[i] == '\0')
		return (-2);
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		res *= 10;
		res += (str[i++] - 48);
	}
	if (str[i] != '\0' || (res * n) <= 0)
		return (-2);
	return (res * n);
}
