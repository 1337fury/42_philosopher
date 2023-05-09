

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
	(*args)->sim_over = false;
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
	sem_wait(arguments->semaphores->death);
	kill_childs(arguments->childs, arguments->n_philos);
	// wait_process(arguments);
	return (EXIT_SUCCESS);
}