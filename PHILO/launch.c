/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdeel-o < abdeel-o@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 17:16:32 by abdeel-o          #+#    #+#             */
/*   Updated: 2023/04/18 16:18:46 by abdeel-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	crt_launch(t_list *list, t_args *args)
{
	int		i;
	t_philo	*curr;

	curr = list->head;
	i = -1;
	pthread_mutex_init(&args->prnt_protect, NULL);
	pthread_mutex_init(&args->status, NULL);
	while (curr && ++i < args->n_philos)
	{
		curr->last_meal_time = current_time();
		if (pthread_create(&curr->philo, NULL, philo_routine, (t_philo *)curr))
			return (EXIT_FAILURE);
		pthread_detach(curr->philo);
		curr = curr->next;
	}
	return (EXIT_SUCCESS);
}
