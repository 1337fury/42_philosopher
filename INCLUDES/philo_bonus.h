/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdeel-o < abdeel-o@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 02:35:36 by abdeel-o          #+#    #+#             */
/*   Updated: 2023/05/09 10:58:03 by abdeel-o         ###   ########.fr       */
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
#include <signal.h>


typedef struct s_sem
{
	sem_t	*forks;
	sem_t	*print;
	sem_t	*last_meal;
	sem_t	*death;
}	t_sem;

typedef struct g_args
{
	int			n_philos;
	long long	t_die;
	int			t_eat;
	int			t_sleep;
	int 		l_meal;
	int			sim_over;
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
long long	current_time(void);
long long	b_current_time(void);
void	waiting(long long time);
void	put_msg(t_philo *philo, char *status);
void	routine(t_philo *philo);
int	b_init(t_args **args, char **av);
int	create_forks(t_args *args);
int	create_philosophers(t_args *args, t_philo *philo);
int	kill_childs(int *pids, int N);
void	wait_process(t_args	*arguments);
// void	free_tab(char **tab);
void	p_error();

#endif