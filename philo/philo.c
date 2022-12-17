/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorobert <lorobert@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 14:48:31 by lorobert          #+#    #+#             */
/*   Updated: 2022/12/17 15:49:52 by lorobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdlib.h>
#include "philo.h"

int	init_philos(t_vars *vars)
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
	vars->philos = malloc(sizeof(t_philo) * vars->n_philo);
	if (!vars->philos)
		return (1);
	i = 0;
	while (i < vars->n_philo)
	{
		vars->philos[i].index = i + 1;
		vars->philos[i].f_left = &vars->forks[i];
		vars->philos[i].f_right = &vars->forks[(i + 1) % vars->n_philo];
		i++;
	}
	vars->is_dead = 0;
	return (0);
}

t_vars	*parse_args(int argc, char **argv)
{
	t_vars	*vars;

	if (argc < 5 || argc > 6)
		return (NULL);
	vars = malloc(sizeof(t_vars));
	if (!vars)
		return (NULL);
	vars->n_philo = ft_atoi(argv[1]);
	if (init_philos(vars))
	{
		clean(vars);
		return (NULL);
	}
	vars->t_die = ft_atoi(argv[2]);
	vars->t_eat = ft_atoi(argv[3]);
	vars->t_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		vars->n_eat = ft_atoi(argv[5]);
	else
		vars->n_eat = 0;
	vars->start = get_timestamp();
	return (vars);
}

int	check_params(t_vars *vars)
{
	if (vars->n_philo < 2)
	{
		ft_pustr("Not enough philosophers\n");
		return (1);
	}
	else if (vars->n_philo > 100)
	{
		ft_pustr("Too many philosophers\n");
		return (1);
	}
	if (vars->t_die < 0 || vars->t_eat < 0 || vars->t_sleep < 0)
	{
		ft_pustr("Time cannot be negative\n");
		return (1);
	}
	if (vars->n_eat < 0)
	{
		ft_pustr("Meals required cannot be negative\n");
		return (1);
	}
	return (0);
}

void	clean(t_vars *vars)
{
	int	i;

	i = 0;
	if (vars && vars->forks)
	{
		while (i < vars->n_philo)
		{
			pthread_mutex_destroy(&vars->forks[i]);
			i++;
		}
		free(vars->forks);
	}
	if (vars && vars->philos)
		free(vars->philos);
	if (vars)
		free(vars);
}

int	main(int argc, char **argv)
{
	t_vars		*vars;
	int			i;

	vars = parse_args(argc, argv);
	if (!vars)
	{
		print_help();
		return (0);
	}
	if (check_params(vars))
	{
		clean(vars);
		return (0);
	}
	i = 0;
	while (i < vars->n_philo)
	{
		pthread_create(&vars->philos[i].thread, NULL, philosophy, &vars->philos[i]);
		i++;
	}
	i = 0;
	while (i < vars->n_philo)
	{
		pthread_join(&vars->philos[i].thread, NULL);
		i++;
	}
	clean(vars);
	return (0);
}
