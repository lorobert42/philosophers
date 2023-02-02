/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorobert <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 12:36:02 by lorobert          #+#    #+#             */
/*   Updated: 2023/02/02 11:42:43 by lorobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	clean_philos(t_vars *vars)
{
	int	i;

	if (vars && vars->philos)
	{
		i = 0;
		while (i < vars->n_philo)
		{
			pthread_mutex_destroy(&vars->philos[i].last_eat_mutex);
			pthread_mutex_destroy(&vars->philos[i].meals_mutex);
			i++;
		}
		free(vars->philos);
	}
}

void	clean_all(t_vars *vars)
{
	int	i;

	if (vars && vars->forks)
	{
		i = 0;
		while (i < vars->n_philo)
		{
			pthread_mutex_destroy(&vars->forks[i]);
			i++;
		}
		free(vars->forks);
	}
	clean_philos(vars);
	if (vars)
	{
		pthread_mutex_destroy(&vars->print_mutex);
		pthread_mutex_destroy(&vars->end_mutex);
		pthread_mutex_destroy(&vars->n_eat_mutex);
		free(vars);
	}
}
