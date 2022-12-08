/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorobert <lorobert@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 14:48:31 by lorobert          #+#    #+#             */
/*   Updated: 2022/12/07 15:22:52 by lorobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include "philo.h"

void	print_help(void)
{
	write(1, "Usage: ./philo number_of_philosophers time_to_die time_to_eat ", 62);
	write(1, "time_to_sleep [number_of_times_each_philosopher_must_eat]\n", 59);
}

int	main(int argc, char **argv)
{
	int		i;
	t_vars	vars;

	if (argc < 5 || argc > 6)
	{
		print_help();
		return (0);
	}
	vars.n_philo = ft_atoi(argv[1]);
	vars.philos = malloc(sizeof(t_philo) * vars.n_philo);
	i = 0;
	while (i < vars.n_philo)
	{
		vars.philos[i].index = i + 1;
		vars.philos[i].state = thinking;
		i++;
	}
	vars.t_die = ft_atoi(argv[2]);
	vars.t_eat = ft_atoi(argv[3]);
	vars.t_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		vars.n_eat = ft_atoi(argv[5]);
}
