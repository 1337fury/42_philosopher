/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_kill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdeel-o < abdeel-o@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 18:10:15 by abdeel-o          #+#    #+#             */
/*   Updated: 2023/04/14 18:10:33 by abdeel-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	wait_process(t_args	*arguments)
{
	int		i;

	i = -1;
	while (++i < arguments->n_philos)
		waitpid(arguments->childs[i], NULL, 0);
}

int	kill_childs(int *pids, int N)
{
	int	i;
	int	result;

	i = 0;
	while(i < N)
	{
		result = kill(pids[i], SIGTERM);
		if (result)
			return (EXIT_FAILURE);
		i++;
	}
	return (EXIT_SUCCESS);
}
