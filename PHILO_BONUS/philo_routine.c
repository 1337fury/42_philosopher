/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdeel-o < abdeel-o@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 18:01:43 by abdeel-o          #+#    #+#             */
/*   Updated: 2023/05/22 13:53:34 by abdeel-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	start_eat(t_philo *philo)
{
	sem_wait(philo->args->sm->forks);
	put_msg(philo, "has taken a fork");
	sem_wait(philo->args->sm->forks);
	put_msg(philo, "has taken a fork");
	sem_wait(philo->args->sm->last_meal);
	philo->last_meal_time = b_current_time();
	sem_post(philo->args->sm->last_meal);
	put_msg(philo, "is eating");
	waiting(philo->args->t_eat);
	sem_wait(philo->args->sm->nbr_meals_prtc);
	philo->n_meals += 1;
	sem_post(philo->args->sm->nbr_meals_prtc);
	sem_post(philo->args->sm->forks);
	sem_post(philo->args->sm->forks);
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
	while (true)
	{
		start_eat(philo);
		start_sleep(philo);
		start_think(philo);
	}
}
