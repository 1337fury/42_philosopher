/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdeel-o < abdeel-o@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 02:33:50 by abdeel-o          #+#    #+#             */
/*   Updated: 2023/04/04 16:46:59 by abdeel-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

long long	b_current_time(void)
{
	struct timeval	curr;
	long long		ms;

	gettimeofday(&curr, NULL);
	ms = (curr.tv_sec * 1000) + (curr.tv_usec / 1000);
	return (ms);
}

void	waiting(long long time)
{
	long long	end;

	end = b_current_time() + time;
	while (b_current_time() < end)
		usleep(200);
}

void	put_msg(t_philo *philo, char *status)
{
	long long curr_t;
	
	sem_wait(philo->args->semaphores->print_lock);
	curr_t = b_current_time();
	printf("%lld %d %s\n",(curr_t - philo->starting_t), philo->id, status);
	sem_post(philo->args->semaphores->print_lock);
}

void	start_eat(t_philo *philo)
{
	sem_wait(philo->args->semaphores->forks);
	put_msg(philo, "has taken a fork");
	sem_wait(philo->args->semaphores->forks);
	put_msg(philo, "has taken a fork");

	sem_wait(philo->args->semaphores->status);
	philo->last_meal_time = b_current_time();
	sem_post(philo->args->semaphores->status);

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
		// if (philo->args->sim_over)
		// 	return (NULL);
		start_eat(philo);
		start_sleep(philo);
		start_think(philo);
	}
}

void	p_error()
{
	printf("Error\n");
}

void	*checker(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (true)
	{
		sem_wait(philo->args->semaphores->status);
		if (b_current_time() - philo->last_meal_time > philo->args->t_die)
		{
			put_msg(philo, "is died");
			return (NULL);
		}
		sem_post(philo->args->semaphores->status);
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
	sem_wait(args->semaphores->status);
	philo->last_meal_time = b_current_time();
	sem_post(args->semaphores->status);
	pthread_create(&philo->thread, NULL, checker, (void *)philo);
	routine(philo);
}

void	wait_process(t_args	*arguments)
{
	int		i;

	i = -1;
	while (++i < arguments->n_philos)
		waitpid(arguments->childs[i], NULL, 0);
}

void	create_philosophers(t_args *args)
{
	int		i;
	pid_t	pid;

	i = -1;
	args->childs = (pid_t *)malloc(sizeof(pid_t));
	if (!args->childs)
		p_error();
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
		else if (pid > 0)
			args->childs[i] = pid;
	}
}

void	create_forks(t_args *args)
{
	sem_unlink("forks");
	sem_unlink("status");
	sem_unlink("print_lock");
	args->semaphores = (t_sem *)malloc(sizeof(t_sem));
	if (!args->semaphores)
		p_error();
	args->semaphores->forks = sem_open("forks", O_CREAT | O_EXCL, 0644, args->n_philos);
	args->semaphores->status = sem_open("status", O_CREAT | O_EXCL, 0644, 1);
	args->semaphores->print_lock = sem_open("print_lock", O_CREAT | O_EXCL, 0644, 1);
}

int	b_init(t_args **args, char **av)
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
	// pthread_mutex_init(&(*args)->st, NULL);
	return (EXIT_SUCCESS);
}

int main(int ac, char **av)
{
	t_args		*arguments;

	if ((ac != 6 && ac != 5))
		return (EXIT_FAILURE);
	arguments = NULL;
	b_init(&arguments, av);
	create_forks(arguments);
	create_philosophers(arguments);
	wait_process(arguments);
	return (EXIT_SUCCESS);
}
