/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdeel-o < abdeel-o@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 17:16:55 by abdeel-o          #+#    #+#             */
/*   Updated: 2023/04/10 17:31:17 by abdeel-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	*lst_new(int inx, t_args *args)
{
	t_philo	*new_fnode;

	new_fnode = (t_philo *)malloc(sizeof(t_philo));
	if (!new_fnode)
		return (NULL);
	new_fnode->id = inx + 1;
	new_fnode->n_meal = 0;
	new_fnode->args = args;
	pthread_mutex_init(&new_fnode->fork_l, NULL);
	new_fnode->next = NULL;
	new_fnode->prev = NULL;
	return (new_fnode);
}

t_list	*create_list(t_args *args)
{
	t_list		*list;
	t_philo		*curr;
	int			i;

	i = 0;
	list = (t_list *)malloc(sizeof(t_list));
	if (!list)
		return (NULL);
	list->head = lst_new(i, args);
	list->tail = list->head;
	while (++i < args->n_philos)
	{
		curr = lst_new(i, args);
		curr->prev = list->tail;
		list->tail->next = curr;
		list->tail = curr;
	}
	list->head->prev = list->tail;
	list->tail->next = list->head;
	return (list);
}

int	init_all(t_args **args, t_list **list, char **av)
{
	*args = (t_args *)malloc(sizeof(t_args));
	if (!(*args))
		return (EXIT_FAILURE);
	(*args)->n_philos = ft_atoi(av[1]);
	(*args)->t_die = ft_atoi(av[2]);
	(*args)->t_eat = ft_atoi(av[3]);
	(*args)->t_sleep = ft_atoi(av[4]);
	if (av[5])
		(*args)->l_meal = ft_atoi(av[5]);
	else
		(*args)->l_meal = -1;
	if ((*args)->n_philos == -2 || (*args)->t_die == -2 || (*args)->t_eat == -2 
			|| (*args)->t_sleep == -2 || (*args)->l_meal == -2)
		return (print_error((t_args *)*args));
	(*args)->sim_over = false;
	*list = create_list(*args);
	if (!(*list))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
