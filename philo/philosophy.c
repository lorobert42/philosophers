/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorobert <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 13:53:57 by lorobert          #+#    #+#             */
/*   Updated: 2023/02/09 11:43:14 by lorobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philosophy(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->vars->n_eat == 0)
		return (NULL);
	if (philo->vars->n_philo == 1)
	{
		pthread_mutex_lock(philo->f_left);
		print_state(philo, FORK_L);
		ft_sleep(philo->vars->t_die + 100);
		pthread_mutex_unlock(philo->f_left);
		return (NULL);
	}
	if (philo->index % 2 == 1)
		ft_sleep(min(philo->vars->t_die / 2, 10));
	while (!get_end(philo->vars))
	{
		eat_sleep(philo);
	}
	return (NULL);
}
