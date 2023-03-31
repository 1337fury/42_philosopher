/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdeel-o < abdeel-o@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 19:41:28 by abdeel-o          #+#    #+#             */
/*   Updated: 2023/03/31 01:57:36 by abdeel-o         ###   ########.fr       */
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

int	main(int ac, char **av)
{
	t_args		*arguments;
	t_list		*list;

	if ((ac != 6 && ac != 5))
		return (EXIT_FAILURE);
	list = NULL;
	arguments = NULL;
	init_all(&arguments, &list, av);
	crt_launch(list, arguments);
	check_death(list, arguments);
	destroy(&list, arguments);
}
