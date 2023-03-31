#include "philo.h"

void	ft_lstclear(t_philo **philo, int n_philos)
{
	t_philo	*curr;
	t_philo	*next;
	int		i;

	curr = *philo;
	if (!philo)
		return ;
	i = -1;
	while (curr && ++i < n_philos)
	{
		next = curr->next;
		free(curr);
		curr = next;
	}
	*philo = NULL;
}
