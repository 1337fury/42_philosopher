/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdeel-o < abdeel-o@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 18:01:43 by abdeel-o          #+#    #+#             */
/*   Updated: 2023/04/14 18:33:11 by abdeel-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	start_eat(t_philo *philo)
{
	sem_wait(philo->args->semaphores->forks);
	put_msg(philo, "has taken a fork");
	sem_wait(philo->args->semaphores->forks);
	put_msg(philo, "has taken a fork");

	sem_wait(philo->args->semaphores->last_meal);
	philo->last_meal_time = b_current_time();
	sem_post(philo->args->semaphores->last_meal);

	put_msg(philo, "is eating");
	waiting(philo->args->t_eat);
	philo->n_meals += 1;
	sem_post(philo->args->semaphores->forks);
	sem_post(philo->args->semaphores->forks);
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

void	routine(t_philo *philo)
{
	philo->starting_t = b_current_time();
	while (true)
	{
		if (philo->args->sim_over)
			return ;
		start_eat(philo);
		start_sleep(philo);
		start_think(philo);
	}
}
