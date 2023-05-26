/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdeel-o < abdeel-o@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 15:47:57 by abdeel-o          #+#    #+#             */
/*   Updated: 2023/05/15 09:20:40 by abdeel-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	check_meals(t_philo *curr, t_args *args)
{
	int	i;

	i = -1;
	while (curr && ++i < args->n_philos)
	{
		if (curr->n_meal < args->l_meal)
			return (false);
		curr = curr->next;
	}
	return (true);
}

int	check_death(t_list *list, t_args *args)
{
	t_philo	*curr;

	curr = list->head;
	while (true)
	{
		pthread_mutex_lock(&curr->args->status);
		if ((current_time() - curr->last_meal_time) > curr->args->t_die)
		{
			args->sim_over = true;
			pthread_mutex_lock(&curr->args->prnt_protect);
			printf("%lld %d %s\n", (current_time() - curr->starting_t), \
			curr->id, "is died");
			return (EXIT_FAILURE);
		}
		if (args->l_meal != -1 && check_meals(list->head, args))
		{
			args->sim_over = true;
			return (EXIT_FAILURE);
		}
		pthread_mutex_unlock(&curr->args->status);
		curr = curr->next;
		usleep(200);
	}
	return (EXIT_SUCCESS);
}
