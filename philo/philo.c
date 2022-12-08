/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorobert <lorobert@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 14:48:31 by lorobert          #+#    #+#             */
/*   Updated: 2022/12/08 15:38:15 by lorobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include "philo.h"

void	ft_pustr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	write(1, str, i);
}

void	print_help(void)
{
	ft_pustr("Usage: ./philo number_of_philosophers time_to_die time_to_eat ");
	ft_pustr("time_to_sleep [number_of_times_each_philosopher_must_eat]\n");
}

t_vars	*parse_args(int argc, char **argv)
{
	t_vars	*vars;
	int		i;

	if (argc < 5 || argc > 6)
		return (NULL);
	vars = malloc(sizeof(t_vars));
	if (!vars)
		return (NULL);
	vars->n_philo = ft_atoi(argv[1]);
	vars->philos = malloc(sizeof(t_philo) * vars->n_philo);
	i = 0;
	while (i < vars->n_philo)
	{
		vars->philos[i].index = i + 1;
		vars->philos[i].state = thinking;
		i++;
	}
	vars->t_die = ft_atoi(argv[2]);
	vars->t_eat = ft_atoi(argv[3]);
	vars->t_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		vars->n_eat = ft_atoi(argv[5]);
	else
		vars->n_eat = 0;
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

int	main(int argc, char **argv)
{
	t_vars	*vars;

	vars = parse_args(argc, argv);
	if (!vars)
	{
		print_help();
		return (0);
	}
	if (check_params(vars))
	{
		free(vars->philos);
		free(vars);
		return (0);
	}
}
