/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorobert <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 14:48:31 by lorobert          #+#    #+#             */
/*   Updated: 2022/12/22 13:19:47 by lorobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		vars->philos[i].vars = vars;
		vars->philos[i].last_eat = vars->start;
		vars->philos[i].meals = 0;
		i++;
	}
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

t_vars	*parse_args(int argc, char **argv)
{
	t_vars	*vars;

	if (argc < 5 || argc > 6)
		return (NULL);
	vars = malloc(sizeof(t_vars));
	if (!vars)
		return (NULL);
	vars->n_philo = ft_atoi(argv[1]);
	vars->t_die = ft_atoi(argv[2]);
	vars->t_eat = ft_atoi(argv[3]);
	vars->t_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		vars->n_eat = ft_atoi(argv[5]);
	else
		vars->n_eat = -1;
	vars->start = get_timestamp();
	if (init_philos(vars))
	{
		clean(vars);
		return (NULL);
	}
	return (vars);
}

int	check_params(int argc, char **argv)
{
	if (ft_atoi(argv[1]) < 1)
	{
		printf("Not enough philosophers\n");
		return (1);
	}
	else if (ft_atoi(argv[1]) > 250)
	{
		printf("Too many philosophers\n");
		return (1);
	}
	if (ft_atoi(argv[2]) < 0 || ft_atoi(argv[3]) < 0 || ft_atoi(argv[4]) < 0)
	{
		printf("Time cannot be negative\n");
		return (1);
	}
	if (argc == 6 && ft_atoi(argv[5]) < 0)
	{
		printf("Meals required cannot be negative\n");
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
	{
		pthread_mutex_destroy(&vars->print_mutex);
		pthread_mutex_destroy(&vars->end_mutex);
		pthread_mutex_destroy(&vars->n_eat_mutex);
		free(vars);
	}
}

int	main(int argc, char **argv)
{
	t_vars		*vars;
	int			i;

	if (argc > 6 || argc < 5)
	{
		print_help();
		return (0);
	}
	if (check_params(argc, argv))
		return (0);
	vars = parse_args(argc, argv);
	if (!vars)
	{
		print_help();
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
		pthread_join(vars->philos[i].thread, NULL);
		i++;
	}
	clean(vars);
	return (0);
}
