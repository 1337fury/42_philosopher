/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_all.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdeel-o < abdeel-o@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 18:04:38 by abdeel-o          #+#    #+#             */
/*   Updated: 2023/04/15 21:03:24 by abdeel-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*checker(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (true)
	{
		sem_wait(philo->args->semaphores->last_meal);
		if (b_current_time() - philo->last_meal_time > philo->args->t_die)
		{
			sem_post(philo->args->semaphores->last_meal);
			put_msg(philo, "is died");
			philo->args->sim_over = true;
			sem_post(philo->args->semaphores->death);
			return (NULL);
		}
		sem_post(philo->args->semaphores->last_meal);
	}
	return (NULL);
}

void	creator(t_args *args, int index)
{
	t_philo	*philo;

	philo = (t_philo *)malloc(sizeof(t_philo));
	memset(philo, 0, sizeof(t_philo));
	if (!philo)
		p_error();
	philo->id = index + 1;
	philo->n_meals = 0;
	philo->args = args;
	sem_wait(philo->args->semaphores->last_meal);
	philo->last_meal_time = b_current_time();
	sem_post(philo->args->semaphores->last_meal);
	pthread_create(&philo->thread, NULL, checker, (void *)philo);
	routine(philo);
}

void	create_philosophers(t_args *args)
{
	int		i;
	pid_t	pid;

	i = -1;
	args->childs = (pid_t *)malloc(sizeof(pid_t) * args->n_philos);
	if (!args->childs)
		p_error();
	sem_wait(args->semaphores->death);
	while (++i < args->n_philos)
	{
		pid = fork();
		if (pid == -1)
			exit(1);
		else if (pid == 0)
		{
			creator(args, i);
			exit(EXIT_SUCCESS);	
		}
		args->childs[i] = pid;
	}
}

void	create_forks(t_args *args)
{
	sem_unlink("forks");
	sem_unlink("print");
	sem_unlink("last_meal");
	sem_unlink("death");
	args->semaphores = (t_sem *)malloc(sizeof(t_sem));
	if (!args->semaphores)
		p_error();
	args->semaphores->forks = sem_open("forks", O_CREAT, 0644, args->n_philos);
	args->semaphores->print = sem_open("print", O_CREAT, 0644, 1);
	args->semaphores->last_meal = sem_open("last_meal", O_CREAT, 0644, 1);
	args->semaphores->death = sem_open("death", O_CREAT, 0644, 1);
}
