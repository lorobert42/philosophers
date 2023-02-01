/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorobert <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 13:53:57 by lorobert          #+#    #+#             */
/*   Updated: 2023/02/01 11:17:55 by lorobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	clean(t_philo *philo)
{
	pthread_mutex_destroy(&philo->last_eat_mutex);
}

void	*philosophy(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	philo->last_eat = get_timestamp();
	if (philo->vars->n_eat == 0)
		return (NULL);
	if (philo->vars->n_philo == 1)
	{
		pthread_mutex_lock(philo->f_left);
		print_state(philo, FORK_L);
		ft_sleep(philo, philo->vars->t_die + 100);
		return (NULL);
	}
	if (philo->index % 2 == 1)
		ft_sleep(philo, min(philo->vars->t_die / 2, 10));
	while (!get_end(philo->vars))
	{
		eat_sleep(philo);
	}
	clean(philo);
	return (NULL);
}
