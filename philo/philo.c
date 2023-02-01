/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorobert <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 14:48:31 by lorobert          #+#    #+#             */
/*   Updated: 2023/02/01 12:38:25 by lorobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
	if (init(vars))
	{
		clean_all(vars);
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

void	start(t_vars *vars)
{
	int	i;

	vars->start = get_timestamp();
	i = 0;
	while (i < vars->n_philo)
	{
		pthread_create(&vars->philos[i].thread, NULL,
			philosophy, &vars->philos[i]);
		i++;
	}
	pthread_create(&vars->thread, NULL, supervise, vars);
	i = 0;
	while (i < vars->n_philo)
	{
		pthread_join(vars->philos[i].thread, NULL);
		i++;
	}
	pthread_join(vars->thread, NULL);
}

int	main(int argc, char **argv)
{
	t_vars		*vars;

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
	start(vars);
	return (0);
}
