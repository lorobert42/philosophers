/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorobert <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 09:52:15 by lorobert          #+#    #+#             */
/*   Updated: 2023/02/01 10:00:58 by lorobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_forks(t_vars *vars)
{
	int	i;

	vars->forks = malloc(sizeof(pthread_mutex_t) * vars->n_philo);
	if (!vars->forks)
		return (1);
	i = 0;
	while (i < vars->n_philo)
	{
		if (pthread_mutex_init(&vars->forks[i], NULL))
			return (1);
		i++;
	}
	return (0);
}

int	init_philos(t_vars *vars)
{
	int	i;

	vars->philos = malloc(sizeof(t_philo) * vars->n_philo);
	if (!vars->philos)
		return (1);
	i = 0;
	while (i < vars->n_philo)
	{
		vars->philos[i].index = i + 1;
		vars->philos[i].f_left = &vars->forks[i];
		vars->philos[i].f_right = &vars->forks[(i + 1) % vars->n_philo];
		vars->philos[i].vars = vars;
		vars->philos[i].last_eat = vars->start;
		vars->philos[i].meals = 0;
		if (pthread_mutex_init(&vars->philos[i].last_eat_mutex, NULL))
			return (1);
		i++;
	}
	return (0);
}

int	init_vars(t_vars *vars)
{
	if (pthread_mutex_init(&vars->n_eat_mutex, NULL))
		return (1);
	if (pthread_mutex_init(&vars->print_mutex, NULL))
		return (1);
	if (pthread_mutex_init(&vars->end_mutex, NULL))
		return (1);
	vars->must_end = 0;
	vars->all_meals = 0;
	return (0);
}

int	init(t_vars *vars)
{
	if (init_forks(vars))
		return (1);
	if (init_philos(vars))
		return (1);
	if (init_vars(vars))
		return (1);
	return (0);
}
