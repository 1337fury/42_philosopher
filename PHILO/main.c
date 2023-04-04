/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdeel-o < abdeel-o@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 19:41:28 by abdeel-o          #+#    #+#             */
/*   Updated: 2023/03/31 15:48:15 by abdeel-o         ###   ########.fr       */
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
	init_all(&arguments, &list, av);
	crt_launch(list, arguments);
	check_death(list, arguments);
	destroy(&list, arguments);
}
