/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorobert <lorobert@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 14:47:54 by lorobert          #+#    #+#             */
/*   Updated: 2022/12/21 14:57:42 by lorobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <pthread.h>
#include "philo.h"

void	think(t_philo *philo)
{
	time_t	think_time;

	think_time = philo->last_eat + philo->vars->t_die - get_timestamp();
	print_state(philo, THINKING);
	ft_sleep(philo, think_time);
}

void	eat_sleep(t_philo *philo)
{
	pthread_mutex_lock(philo->f_left);
	print_state(philo, FORK_L);
	if (philo->vars->must_end)
	{
		pthread_mutex_unlock(philo->f_left);
		return ;
	}
	pthread_mutex_lock(philo->f_right);
	print_state(philo, FORK_R);
	if (philo->vars->must_end)
	{
		pthread_mutex_unlock(philo->f_left);
		pthread_mutex_unlock(philo->f_right);
		return ;
	}
	print_state(philo, EATING);
	philo->last_eat = get_timestamp();
	ft_sleep(philo, philo->vars->t_eat);
	pthread_mutex_lock(&philo->vars->n_eat_mutex);
	philo->meals++;
	if (philo->vars->n_eat >= 0 && philo->meals == philo->vars->n_eat)
	{
		philo->vars->all_meals++;
		if (philo->vars->all_meals == philo->vars->n_eat)
			philo->vars->must_end = 1;
	}
	pthread_mutex_unlock(&philo->vars->n_eat_mutex);
	pthread_mutex_unlock(philo->f_left);
	pthread_mutex_unlock(philo->f_right);
	if (philo->vars->must_end)
		return ;
	print_state(philo, SLEEPING);
	ft_sleep(philo, philo->vars->t_sleep);
	if (philo->vars->must_end)
		return ;
	think(philo);
}
