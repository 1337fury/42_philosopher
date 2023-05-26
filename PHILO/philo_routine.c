/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdeel-o < abdeel-o@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 17:17:07 by abdeel-o          #+#    #+#             */
/*   Updated: 2023/05/19 15:55:30 by abdeel-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	start_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->fork_l);
	put_msg(philo, "has taken a fork");
	pthread_mutex_lock(&philo->prev->fork_l);
	put_msg(philo, "has taken a fork");
	pthread_mutex_lock(&philo->args->status);
	philo->last_meal_time = current_time();
	pthread_mutex_unlock(&philo->args->status);
	put_msg(philo, "is eating");
	waiting(philo->args->t_eat);
	pthread_mutex_lock(&philo->args->status);
	philo->n_meal += 1;
	pthread_mutex_unlock(&philo->args->status);
	pthread_mutex_unlock(&philo->fork_l);
	pthread_mutex_unlock(&philo->prev->fork_l);
}

void	start_sleep(t_philo *philo)
{
	put_msg(philo, "is sleeping");
	waiting(philo->args->t_sleep);
}

void	start_think(t_philo *philo)
{
	put_msg(philo, "is thinking");
}

void	*philo_routine(void *arg)
{
	t_philo		*philo;

	philo = (t_philo *)arg;
	philo->starting_t = current_time();
	if (!(philo->id % 2))
		waiting(philo->args->t_eat / 2);
	while (true)
	{
		pthread_mutex_lock(&philo->args->status);
		if (philo->args->sim_over)
		{
			pthread_mutex_unlock(&philo->args->status);
			return (NULL);
		}
		pthread_mutex_unlock(&philo->args->status);
		start_eat(philo);
		start_sleep(philo);
		start_think(philo);
	}
	return (NULL);
}
