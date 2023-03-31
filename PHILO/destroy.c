/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdeel-o < abdeel-o@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 01:55:38 by abdeel-o          #+#    #+#             */
/*   Updated: 2023/03/31 01:56:07 by abdeel-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	destroy(t_list **philos, t_args *args)
{
	int		i;
	t_philo	*curr;

	i = -1;
	curr = (*philos)->head;
	while(curr && ++i < args->n_philos)
	{
		pthread_mutex_destroy(&curr->fork_l);
		curr = curr->next;
	}
	pthread_mutex_destroy(&args->prnt_protect);
	pthread_mutex_destroy(&args->status);
	curr = (*philos)->head;
	ft_lstclear(&curr, args->n_philos);
	free(args);
}
