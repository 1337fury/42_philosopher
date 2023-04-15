/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdeel-o < abdeel-o@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 17:17:00 by abdeel-o          #+#    #+#             */
/*   Updated: 2023/04/11 03:11:30 by abdeel-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// 1sec = 10^3 msec
// 1msec = 10^3 usec
// 1sec = 10^6 usec
long long	current_time(void)
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

	end = current_time() + time;
	while (current_time() < end)
		usleep(200);
}

void	put_msg(t_philo *philo, char *status)
{
	long long	curr_t;

	curr_t = current_time();
	pthread_mutex_lock(&philo->args->prnt_protect);
	printf("%lld %d %s\n", (curr_t - philo->starting_t), philo->id, status);
	pthread_mutex_unlock(&philo->args->prnt_protect);
}
