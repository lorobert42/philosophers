/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorobert <lorobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 10:19:22 by lorobert          #+#    #+#             */
/*   Updated: 2022/12/22 10:26:50 by lorobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	get_end(t_vars *vars)
{
	int	res;

	pthread_mutex_lock(&vars->end_mutex);
	if (vars->must_end)
		res = 1;
	else
		res = 0;
	pthread_mutex_unlock(&vars->end_mutex);
	return (res);
}

void	set_end(t_vars *vars)
{
	pthread_mutex_lock(&vars->end_mutex);
	vars->must_end = 1;
	pthread_mutex_unlock(&vars->end_mutex);
}
