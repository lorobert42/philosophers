/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorobert <lorobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 15:41:14 by lorobert          #+#    #+#             */
/*   Updated: 2022/12/22 11:53:35 by lorobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_sleep(t_philo *philo, time_t duration)
{
	time_t	end;

	end = get_timestamp() + duration;
	while (get_timestamp() < end && !get_end(philo->vars))
	{
		if (get_timestamp() - philo->last_eat > philo->vars->t_die)
		{
			set_end(philo->vars);
			print_state(philo, DEAD);
			break ;
		}
		usleep(100);
	}
}
