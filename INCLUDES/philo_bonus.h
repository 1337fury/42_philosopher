/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdeel-o < abdeel-o@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 02:35:36 by abdeel-o          #+#    #+#             */
/*   Updated: 2023/03/27 18:28:22 by abdeel-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <semaphore.h>
# include <stdlib.h>
# include <sys/time.h>
# include <time.h>
# include <stdio.h>
# include <unistd.h>
# include <stdbool.h>

#define MSG "/msg"
#define	EAT "/eat"

typedef struct s_data {
	
} t_data;

typedef struct g_args
{
	int				pid;
	int				philo_id;
	int				n_philos;
	long long		t_die;
	int				t_eat;
	int				t_sleep;
	int 			l_meal;
	long long		starting_t;
	t_data			semaphores;
}	t_args;

typedef struct g_philo
{
	bool			death;
	int				n_meal;
	long			last_meal_time;
	pthread_t		thread;
	t_args			*args;
}	t_philo;

void	init(t_args *args, char **av);
long long	calc_timestamp(void);
int	ft_atoi(const char *str);

#endif