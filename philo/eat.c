/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorobert <lorobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 14:47:54 by lorobert          #+#    #+#             */
/*   Updated: 2022/12/22 10:41:56 by lorobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	think(t_philo *philo)
{
	time_t	think_time;

	pthread_mutex_lock(&philo->vars->print_mutex);
	print_state(philo, THINKING);
	pthread_mutex_unlock(&philo->vars->print_mutex);
	think_time = philo->last_eat + philo->vars->t_die - get_timestamp();
	ft_sleep(philo, think_time);
}

void	eat_sleep(t_philo *philo)
{
	pthread_mutex_lock(philo->f_left);
	pthread_mutex_lock(&philo->vars->print_mutex);
	print_state(philo, FORK_L);
	pthread_mutex_unlock(&philo->vars->print_mutex);
	if (get_end(philo->vars))
	{
		pthread_mutex_unlock(philo->f_left);
		return ;
	}
	pthread_mutex_lock(philo->f_right);
	pthread_mutex_lock(&philo->vars->print_mutex);
	print_state(philo, FORK_R);
	pthread_mutex_unlock(&philo->vars->print_mutex);
	if (get_end(philo->vars))
	{
		pthread_mutex_unlock(philo->f_left);
		pthread_mutex_unlock(philo->f_right);
		return ;
	}
	pthread_mutex_lock(&philo->vars->print_mutex);
	print_state(philo, EATING);
	pthread_mutex_unlock(&philo->vars->print_mutex);
	philo->last_eat = get_timestamp();
	ft_sleep(philo, philo->vars->t_eat);
	pthread_mutex_lock(&philo->vars->n_eat_mutex);
	philo->meals++;
	if (philo->vars->n_eat >= 0 && philo->meals == philo->vars->n_eat)
	{
		philo->vars->all_meals++;
		if (philo->vars->all_meals == philo->vars->n_philo)
		{
			set_end(philo->vars);
		}
	}
	pthread_mutex_unlock(&philo->vars->n_eat_mutex);
	pthread_mutex_unlock(philo->f_left);
	pthread_mutex_unlock(philo->f_right);
	if (get_end(philo->vars))
		return ;
	pthread_mutex_lock(&philo->vars->print_mutex);
	print_state(philo, SLEEPING);
	pthread_mutex_unlock(&philo->vars->print_mutex);
	ft_sleep(philo, philo->vars->t_sleep);
	if (get_end(philo->vars))
		return ;
	think(philo);
}
