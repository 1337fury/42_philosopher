/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timestamp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdeel-o < abdeel-o@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 19:20:19 by abdeel-o          #+#    #+#             */
/*   Updated: 2023/03/27 12:17:09 by abdeel-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

long long	calc_timestamp(void)
{
	struct timeval	curr;
	long long		ms;

	gettimeofday(&curr, NULL);
	ms = (curr.tv_sec * 1000) + (curr.tv_usec / 1000);
	return (ms);
}
