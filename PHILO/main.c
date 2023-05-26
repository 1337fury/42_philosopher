/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdeel-o < abdeel-o@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 19:41:28 by abdeel-o          #+#    #+#             */
/*   Updated: 2023/05/15 08:45:43 by abdeel-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_args		*arguments;
	t_list		*list;

	if ((ac != 6 && ac != 5))
		return (EXIT_FAILURE);
	list = NULL;
	arguments = NULL;
	if (init_all(&arguments, &list, av))
		return (EXIT_FAILURE);
	if (crt_launch(list, arguments))
	{
		destroy(&list, arguments);
		return (EXIT_FAILURE);
	}
	check_death(list, arguments);
	destroy(&list, arguments);
	return (EXIT_SUCCESS);
}
