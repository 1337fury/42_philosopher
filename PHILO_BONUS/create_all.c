/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_all.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdeel-o < abdeel-o@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 18:04:38 by abdeel-o          #+#    #+#             */
/*   Updated: 2023/05/09 12:32:18 by abdeel-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

bool	check_meals(t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < philo->args->n_philos)
	{
		if (philo->n_meals < philo->args->l_meal)
			return (false);
	}
	return (true);
}

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
			sem_wait(philo->args->semaphores->print);
			printf("%lld %d %s\n",(b_current_time() - philo->starting_t), philo->id, "died");
			philo->args->sim_over = true;
			sem_post(philo->args->semaphores->death);
			return (NULL);
		}
		sem_post(philo->args->semaphores->last_meal);
		if (check_meals(philo) && philo->args->l_meal != -1)
		{
			sleep(1);
			sem_post(philo->args->semaphores->death);
		}
	}
	return (NULL);
}

int	creator(t_args *args, int index, t_philo *philo)
{
	philo = (t_philo *)malloc(sizeof(t_philo));
	if (!philo)
		return (free(args->childs), free(args), EXIT_FAILURE);
	memset(philo, 0, sizeof(t_philo));
	philo->id = index + 1;
	philo->n_meals = 0;
	philo->args = args;
	if (sem_wait(philo->args->semaphores->last_meal) == -1)
		return (free(philo), free(args->childs), free(args), EXIT_FAILURE);
	philo->last_meal_time = b_current_time();
	if (sem_post(philo->args->semaphores->last_meal) == -1)
		return (free(philo), free(args->childs), free(args), EXIT_FAILURE);
	if (pthread_create(&philo->thread, NULL, checker, (void *)philo))
		return (free(philo), free(args->childs), free(args), EXIT_FAILURE);
	routine(philo);
	return (EXIT_SUCCESS);
}

int	create_philosophers(t_args *args, t_philo *philo)
{
	int		i;
	pid_t	pid;

	i = -1;
	args->childs = (pid_t *)malloc(sizeof(pid_t) * args->n_philos);
	if (!args->childs)
		return (free(args), EXIT_FAILURE);
	if (sem_wait(args->semaphores->death) == -1)
		return (free(args->childs), free(args), EXIT_FAILURE);
	while (++i < args->n_philos)
	{
		pid = fork();
		if (pid == -1)
			return (free(args->childs), free(args), EXIT_FAILURE);
		else if (pid == 0)
		{
			if (creator(args, i, philo))
				return (EXIT_FAILURE);
			exit(EXIT_SUCCESS);		
		}
		args->childs[i] = pid;
	}
	return (EXIT_SUCCESS);
}

int	create_forks(t_args *args)
{
	sem_unlink("forks");
	sem_unlink("print");
	sem_unlink("last_meal");
	sem_unlink("death");
	args->semaphores = (t_sem *)malloc(sizeof(t_sem));
	if (!args->semaphores)
		return (free(args), EXIT_FAILURE);
	args->semaphores->forks = sem_open("forks", O_CREAT, 0644, args->n_philos);
	args->semaphores->print = sem_open("print", O_CREAT, 0644, 1);
	args->semaphores->last_meal = sem_open("last_meal", O_CREAT, 0644, 1);
	args->semaphores->death = sem_open("death", O_CREAT, 0644, 1);
	if (args->semaphores->forks == SEM_FAILED
		|| args->semaphores->print == SEM_FAILED
		|| args->semaphores->last_meal == SEM_FAILED
		|| args->semaphores->death == SEM_FAILED)
		return (free(args), EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
