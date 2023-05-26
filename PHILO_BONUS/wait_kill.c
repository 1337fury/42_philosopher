/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_kill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdeel-o < abdeel-o@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 18:10:15 by abdeel-o          #+#    #+#             */
/*   Updated: 2023/05/22 16:05:33 by abdeel-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	kill_childs(int *pids, int N)
{
	int	i;

	i = -1;
	while (++i < N)
		kill(pids[i], SIGKILL);
	return (free(pids), EXIT_SUCCESS);
}
