/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdeel-o < abdeel-o@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 19:20:19 by abdeel-o          #+#    #+#             */
/*   Updated: 2023/05/10 15:54:28 by abdeel-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

// void	free_tab(char **tab)
// {
// 	int	i;

// 	i = 0;
// 	if (tab)
// 	{
// 		while (tab[i])
// 			free(tab[i++]);
// 		free(tab);
// 	}
// }

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	if (!s1 || !s2)
		return (0);
	while (1)
	{
		if (s1[i] != s2[i])
			return (0);
		if (s1[i] == '\0' || s2[i] == '\0')
		{
			if (s1[i] == '\0' && s2[i] == '\0')
				return (1);
			else
				return (0);
		}
		i++;
	}
	return (0);
}

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
	
	sem_wait(philo->args->sm->print);
	curr_t = b_current_time();
	printf("%lld %d %s\n",(curr_t - philo->starting_t), philo->id, status);
	sem_post(philo->args->sm->print);
}
