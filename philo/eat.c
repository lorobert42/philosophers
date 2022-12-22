/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorobert <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 14:47:54 by lorobert          #+#    #+#             */
/*   Updated: 2022/12/22 13:19:31 by lorobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	think(t_philo *philo)
{
	time_t	think_time;

	print_state(philo, THINKING);
	think_time = philo->last_eat + philo->vars->t_die - get_timestamp();
	ft_sleep(philo, think_time);
}

void	check_meals(t_philo *philo)
{
	if (philo->vars->n_eat >= 0 && philo->meals == philo->vars->n_eat)
	{
		philo->vars->all_meals++;
		if (philo->vars->all_meals == philo->vars->n_philo)
			set_end(philo->vars);
	}
}

void	add_meal(t_philo *philo)
{
	pthread_mutex_lock(&philo->vars->n_eat_mutex);
	philo->meals++;
	check_meals(philo);
	pthread_mutex_unlock(&philo->vars->n_eat_mutex);
}

void	eat_sleep(t_philo *philo)
{
	pthread_mutex_lock(philo->f_left);
	print_state(philo, FORK_L);
	if (get_end(philo->vars))
	{
		pthread_mutex_unlock(philo->f_left);
		return ;
	}
	pthread_mutex_lock(philo->f_right);
	print_state(philo, FORK_R);
	if (get_end(philo->vars))
	{
		pthread_mutex_unlock(philo->f_left);
		pthread_mutex_unlock(philo->f_right);
		return ;
	}
	print_state(philo, EATING);
	philo->last_eat = get_timestamp();
	ft_sleep(philo, philo->vars->t_eat);
	add_meal(philo);
	pthread_mutex_unlock(philo->f_left);
	pthread_mutex_unlock(philo->f_right);
	print_state(philo, SLEEPING);
	ft_sleep(philo, philo->vars->t_sleep);
	think(philo);
}
