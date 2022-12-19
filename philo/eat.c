/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorobert <lorobert@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 14:47:54 by lorobert          #+#    #+#             */
/*   Updated: 2022/12/19 18:35:54 by lorobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include "philo.h"

void	eat_sleep(t_philo *philo)
{
	pthread_mutex_lock(philo->f_left);
	print_state(philo, FORK_L);
	pthread_mutex_lock(philo->f_right);
	print_state(philo, FORK_R);
	print_state(philo, EATING);
	philo->last_eat = get_timestamp();
	pthread_mutex_unlock(philo->f_left);
	pthread_mutex_unlock(philo->f_right);
	ft_sleep(philo->vars->t_eat);
	print_state(philo, SLEEPING);
	ft_sleep(philo->vars->t_sleep);
}
