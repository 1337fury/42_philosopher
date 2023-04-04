/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdeel-o < abdeel-o@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 02:35:36 by abdeel-o          #+#    #+#             */
/*   Updated: 2023/04/04 16:43:56 by abdeel-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <semaphore.h>
# include <pthread.h>
# include <stdlib.h>
# include <sys/time.h>
# include <time.h>
# include <stdio.h>
# include <unistd.h>
# include <stdbool.h>
#include <string.h>

#define MSG "/msg"
#define	EAT "/eat"

typedef struct s_sem
{
	sem_t	*forks;
	sem_t	*status;
	sem_t	*print_lock;
}	t_sem;

typedef struct g_args
{
	int			n_philos;
	long long	t_die;
	int			t_eat;
	int			t_sleep;
	int 		l_meal;
	// pthread_mutex_t	st;
	pid_t		*childs;
	t_sem		*semaphores;
}	t_args;


typedef struct g_philo
{
	int				id;
	int				n_meals;
	long			last_meal_time;
	long long		starting_t;
	pthread_t		thread;
	t_args			*args;
}	t_philo;

int	ft_atoi(const char *str);

#endif