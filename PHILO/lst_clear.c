/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_clear.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdeel-o < abdeel-o@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 03:08:36 by abdeel-o          #+#    #+#             */
/*   Updated: 2023/04/11 03:08:37 by abdeel-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_lstclear(t_philo **philo, int n_philos)
{
	t_philo	*curr;
	t_philo	*next;
	int		i;

	if (!philo)
		return ;
	curr = *philo;
	i = -1;
	while (curr && ++i < n_philos)
	{
		next = curr->next;
		free(curr);
		curr = next;
	}
	*philo = NULL;
}
