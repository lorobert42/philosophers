/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   supervisor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorobert <lorobert@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 08:31:51 by lorobert          #+#    #+#             */
/*   Updated: 2023/01/21 16:10:11 by lorobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	check_philo(t_vars *vars, int i)
{
	pthread_mutex_lock(&vars->philos[i].last_eat_mutex);
	if (get_timestamp() - vars->philos[i].last_eat > vars->t_die)
	{
		print_state(&vars->philos[i], DEAD);
		set_end(vars);
		pthread_mutex_unlock(&vars->philos[i].last_eat_mutex);
		return ;
	}
	pthread_mutex_unlock(&vars->philos[i].last_eat_mutex);
	if (vars->n_eat >= 0 && vars->philos[i].meals >= vars->n_eat)
		vars->all_meals++;
	i++;
	usleep(100);
}

void	*supervise(void *arg)
{
	t_vars	*vars;
	int		i;

	vars = (t_vars *)arg;
	while (!get_end(vars))
	{
		i = 0;
		vars->all_meals = 0;
		while (i < vars->n_philo)
		{
			check_philo(vars, i);
		}
		if (vars->all_meals == vars->n_philo)
			set_end(vars);
	}
	return (NULL);
}
