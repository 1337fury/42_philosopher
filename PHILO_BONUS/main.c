/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdeel-o < abdeel-o@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 02:33:50 by abdeel-o          #+#    #+#             */
/*   Updated: 2023/05/12 19:51:31 by abdeel-o         ###   ########.fr       */
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
		return (free(args->sm), EXIT_FAILURE);
	if (create_philosophers(args, philo))
		return (EXIT_FAILURE);
	// if (sem_wait(args->sm->death) == -1)
	// 	return (free(args->sm), free(philo), free(args->childs), free(args), 1);
	wait_process(args, args->childs);
	// if (kill_childs(args->childs, args->n_philos))
	// 	return (free(args->sm), free(philo), free(args->childs), free(args), 1);
	return (EXIT_SUCCESS);
}
