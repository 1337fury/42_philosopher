/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdeel-o < abdeel-o@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 19:26:19 by abdeel-o          #+#    #+#             */
/*   Updated: 2023/03/31 01:58:39 by abdeel-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdlib.h>
# include <sys/time.h>
# include <time.h>
# include <stdio.h>
# include <unistd.h>
# include <stdbool.h>


typedef struct g_args
{
	int			n_philos;
	long long	t_die;
	int			t_eat;
	int			t_sleep;
	int 		l_meal;
	bool		sim_over;
	pthread_mutex_t	prnt_protect;
	pthread_mutex_t	status;
}	t_args;

typedef struct	g_list
{
	struct g_philo *head;
	struct g_philo *tail;
}	t_list;

typedef struct g_philo
{
	int				id;
	int				n_meal;
	long			last_meal_time;
	long long		starting_t;
	t_args			*args;
	pthread_mutex_t	fork_l;
	pthread_t		philo;
	struct g_philo *next;
	struct g_philo *prev;
}	t_philo;

int			ft_atoi(const char *str);
void		*philo_routine(void *arg);
void		put_msg(t_philo *philo, char *status);
void		waiting(long long time);
long long	current_time(void);
int			init_all(t_args **args, t_list **list, char **av);
int			crt_launch(t_list *list, t_args *args);
void		ft_lstclear(t_philo **philo, int n_philos);
void		destroy(t_list **philos, t_args *args);

#endif