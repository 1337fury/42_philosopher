/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdeel-o < abdeel-o@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 17:17:07 by abdeel-o          #+#    #+#             */
/*   Updated: 2023/04/18 16:20:00 by abdeel-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	start_eat(t_philo *philo)
{
	t_philo	*first;
	t_philo	*second;

	pthread_mutex_lock(&philo->args->status);
	if (philo->args->sim_over)
		return ;
	pthread_mutex_unlock(&philo->args->status);
	if (philo->id % 2 == 0)
	{
		first = philo;
		second = philo->next;
	}
	else
	{
		first = philo->next;
		second = philo;
	}
	if (pthread_mutex_lock(&first->fork_l))
		return ;
	put_msg(philo, "has taken a fork");
	if (pthread_mutex_lock(&second->fork_l))
		return ;
	put_msg(philo, "has taken a fork");
	pthread_mutex_lock(&philo->args->status);
	philo->last_meal_time = current_time();
	put_msg(philo, "is eating");
	pthread_mutex_unlock(&philo->args->status);
	waiting(philo->args->t_eat);
	philo->n_meal += 1;
	if (pthread_mutex_unlock(&philo->fork_l))
		return ;
	if (pthread_mutex_unlock(&philo->next->fork_l))
		return ;
}

void	start_sleep(t_philo *philo)
{
	pthread_mutex_lock(&philo->args->status);
	if (philo->args->sim_over)
		return ;
	pthread_mutex_unlock(&philo->args->status);
	put_msg(philo, "is sleeping");
	waiting(philo->args->t_sleep);
}

void	start_think(t_philo *philo)
{
	pthread_mutex_lock(&philo->args->status);
	if (philo->args->sim_over)
		return ;
	pthread_mutex_unlock(&philo->args->status);
	put_msg(philo, "is thinking");
}

void	*philo_routine(void *arg)
{
	t_philo		*philo;

	philo = (t_philo *)arg;
	philo->starting_t = current_time();
	while (true)
	{
		if (philo->args->sim_over)
			return (NULL);
		start_eat(philo);
		start_sleep(philo);
		start_think(philo);
	}
	return (NULL);
}
