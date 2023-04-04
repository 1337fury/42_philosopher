/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdeel-o < abdeel-o@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 15:47:57 by abdeel-o          #+#    #+#             */
/*   Updated: 2023/03/31 15:48:43 by abdeel-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
				put_msg(curr, "is died");
				return (EXIT_FAILURE);
			}
			pthread_mutex_unlock(&curr->args->status);
			curr = curr->next;
			usleep(200);
		}
		return (EXIT_SUCCESS);
}
