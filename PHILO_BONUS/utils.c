/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdeel-o < abdeel-o@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 19:20:19 by abdeel-o          #+#    #+#             */
/*   Updated: 2023/04/14 17:59:32 by abdeel-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

long long	current_time(void)
{
	struct timeval	curr;
	long long		ms;

	gettimeofday(&curr, NULL);
	ms = (curr.tv_sec * 1000) + (curr.tv_usec / 1000);
	return (ms);
}

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
	
	sem_wait(philo->args->semaphores->print);
	curr_t = b_current_time();
	printf("%lld %d %s\n",(curr_t - philo->starting_t), philo->id, status);
	sem_post(philo->args->semaphores->print);
}
