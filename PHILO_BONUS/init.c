/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdeel-o < abdeel-o@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 18:03:19 by abdeel-o          #+#    #+#             */
/*   Updated: 2023/05/15 19:09:03 by abdeel-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	b_init(t_args **args, char **av)
{
	*args = (t_args *)malloc(sizeof(t_args));
	if (!(*args))
		return (EXIT_FAILURE);
	(*args)->n_philos = ft_atoi(av[1]);
	(*args)->t_die = ft_atoi(av[2]);
	(*args)->t_eat = ft_atoi(av[3]);
	(*args)->t_sleep = ft_atoi(av[4]);
	if (av[5])
		(*args)->l_meal = ft_atoi(av[5]);
	else
		(*args)->l_meal = -1;
	if ((*args)->n_philos == -2 || (*args)->t_die == -2 || (*args)->t_eat == -2
		|| (*args)->t_sleep == -2 || (*args)->l_meal == -2)
		return (print_error((t_args *)*args));
	return (EXIT_SUCCESS);
}
