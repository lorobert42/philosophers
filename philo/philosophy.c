/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorobert <lorobert@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 13:53:57 by lorobert          #+#    #+#             */
/*   Updated: 2022/12/21 14:56:26 by lorobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philosophy(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->vars->n_philo == 1)
	{
		ft_sleep(philo, philo->vars->t_die + 100);
		return (NULL);
	}
	if (philo->index % 2 == 1)
		ft_sleep(philo, philo->vars->t_die / 2);
	while (philo->vars->must_end != 1)
	{
		eat_sleep(philo);
	}
	return (NULL);
}
