/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_kill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdeel-o < abdeel-o@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 18:10:15 by abdeel-o          #+#    #+#             */
/*   Updated: 2023/05/12 20:15:42 by abdeel-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"


int	kill_childs(int *pids, int N)
{
	int	i;

	i = 0;
	while(i < N)
	{
		// if (pids[i] != ignored)
			kill(pids[i], SIGTERM);
		i++;
	}
	return (EXIT_SUCCESS);
}

void	wait_process(t_args	*args, int *pids)
{
	int		status;
	int		i;
	pid_t 	pid;
	

	i =-1;

		pid = waitpid(-1, &status, 0);
		status = (status >> 8) & 255;
		if (status == 3)
		{
			while (++i < args->n_philos - 1)
			{
				pid = waitpid(-1, &status, 0);
				status = (status >> 8) & 255;
				if (status == 1)
					break ;
			}
		}
		kill_childs(pids, args->n_philos);	
}