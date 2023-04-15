/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdeel-o < abdeel-o@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 02:33:50 by abdeel-o          #+#    #+#             */
/*   Updated: 2023/04/15 16:47:37 by abdeel-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int main(int ac, char **av)
{
	t_args		*arguments;

	if ((ac != 6 && ac != 5))
		return (EXIT_FAILURE);
	arguments = NULL;
	b_init(&arguments, av);
	create_forks(arguments);
	create_philosophers(arguments);
	sem_wait(arguments->semaphores->death);
	kill_childs(arguments->childs, arguments->n_philos);
	// wait_process(arguments);
	return (EXIT_SUCCESS);
}
