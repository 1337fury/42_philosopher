/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdeel-o < abdeel-o@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 02:33:50 by abdeel-o          #+#    #+#             */
/*   Updated: 2023/05/09 11:02:27 by abdeel-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int main(int ac, char **av)
{
	t_args		*args;
	t_philo		*philo;

	if ((ac != 6 && ac != 5))
		return (EXIT_FAILURE);
	args = NULL;
	philo = NULL;
	if (b_init(&args, av))
		return (EXIT_FAILURE);
	if (create_forks(args))
		return (EXIT_FAILURE);
	if (create_philosophers(args, philo))
		return (EXIT_FAILURE);
	if (sem_wait(args->semaphores->death) == -1)
		return (free(philo), free(args->childs), free(args), EXIT_FAILURE);
	if (kill_childs(args->childs, args->n_philos))
		return (free(philo), free(args->childs), free(args), EXIT_FAILURE);
	// wait_process(arguments);
	return (EXIT_SUCCESS);
}
