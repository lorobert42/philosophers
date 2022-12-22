/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorobert <lorobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 13:53:57 by lorobert          #+#    #+#             */
/*   Updated: 2022/12/22 10:44:07 by lorobert         ###   ########.fr       */
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
	while (!get_end(philo->vars))
	{
		eat_sleep(philo);
	}
	return (NULL);
}
