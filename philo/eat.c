/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorobert <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 14:47:54 by lorobert          #+#    #+#             */
/*   Updated: 2023/02/02 09:19:45 by lorobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	think(t_philo *philo)
{
	time_t	think_time;

	print_state(philo, THINKING);
	pthread_mutex_lock(&philo->last_eat_mutex);
	think_time = min((philo->vars->t_die - get_timestamp()
				+ philo->last_eat) / 2, 10);
	pthread_mutex_unlock(&philo->last_eat_mutex);
	ft_sleep(philo, think_time);
}

void	eat(t_philo *philo)
{
	print_state(philo, EATING);
	pthread_mutex_lock(&philo->last_eat_mutex);
	philo->last_eat = get_timestamp();
	pthread_mutex_unlock(&philo->last_eat_mutex);
	ft_sleep(philo, philo->vars->t_eat);
	pthread_mutex_lock(&philo->meals_mutex);
	philo->meals++;
	pthread_mutex_unlock(&philo->meals_mutex);
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
	eat(philo);
	print_state(philo, SLEEPING);
	pthread_mutex_unlock(philo->f_left);
	pthread_mutex_unlock(philo->f_right);
	ft_sleep(philo, philo->vars->t_sleep);
	think(philo);
}
