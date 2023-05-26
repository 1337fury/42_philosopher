/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_all.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdeel-o < abdeel-o@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 18:04:38 by abdeel-o          #+#    #+#             */
/*   Updated: 2023/05/22 16:00:58 by abdeel-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

bool	check_meals(t_philo *philo)
{
	if (philo->n_meals < philo->args->l_meal)
		return (false);
	if (philo->id == philo->args->n_philos)
		sem_post(philo->args->sm->exit_prc);
	sem_post(philo->args->sm->last_meal);
	return (true);
}

void	*checker(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (true)
	{
		sem_wait(philo->args->sm->last_meal);
		if (b_current_time() - philo->last_meal_time >= philo->args->t_die)
		{
			put_msg(philo, "died");
			sem_post(philo->args->sm->last_meal);
			return (NULL);
		}
		sem_post(philo->args->sm->last_meal);
		if (philo->args->l_meal != -1 && check_meals(philo))
			return (NULL);
		usleep(200);
	}
	return (NULL);
}

int	creator(t_args *args, int index, t_philo *philo)
{
	philo = (t_philo *)malloc(sizeof(t_philo));
	if (!philo)
		return (EXIT_FAILURE);
	memset(philo, 0, sizeof(t_philo));
	philo->id = index + 1;
	philo->n_meals = 0;
	philo->last_meal_time = args->starting_t;
	philo->args = args;
	if (pthread_create(&philo->thread, NULL, checker, (void *)philo))
		return (free(philo), EXIT_FAILURE);
	pthread_detach(philo->thread);
	routine(philo);
	return (EXIT_SUCCESS);
}

int	create_philosophers(t_args *args, t_philo *philo)
{
	int		i;
	pid_t	pid;

	args->childs = (pid_t *)malloc(sizeof(pid_t) * args->n_philos);
	if (!args->childs)
		return (free(args->sm), free(args), EXIT_FAILURE);
	sem_wait(args->sm->exit_prc);
	i = -1;
	args->starting_t = b_current_time();
	while (++i < args->n_philos)
	{		
		pid = fork();
		if (pid == -1)
			return (free(args->childs), free(args->sm), EXIT_FAILURE);
		else if (pid == 0)
		{
			if (creator(args, i, philo))
				return (free(args->childs), free(args->sm), EXIT_FAILURE);
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
	sem_unlink("nbr_meals_prtc");
	sem_unlink("exit_prc");
	args->sm = (t_sem *)malloc(sizeof(t_sem));
	if (!args->sm)
		return (free(args), EXIT_FAILURE);
	args->sm->forks = sem_open("forks", O_CREAT, 0644, args->n_philos);
	args->sm->print = sem_open("print", O_CREAT, 0644, 1);
	args->sm->last_meal = sem_open("last_meal", O_CREAT, 0644, 1);
	args->sm->nbr_meals_prtc = sem_open("nbr_meals_prtc", O_CREAT, 0644, 1);
	args->sm->exit_prc = sem_open("exit_prc", O_CREAT, 0644, 1);
	if (args->sm->forks == SEM_FAILED
		|| args->sm->print == SEM_FAILED
		|| args->sm->last_meal == SEM_FAILED
		|| args->sm->nbr_meals_prtc == SEM_FAILED
		|| args->sm->exit_prc == SEM_FAILED)
		return (free(args->sm), EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
