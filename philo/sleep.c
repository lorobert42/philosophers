/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorobert <lorobert@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 15:41:14 by lorobert          #+#    #+#             */
/*   Updated: 2022/12/20 14:23:39 by lorobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>
#include <unistd.h>
#include "philo.h"

void	ft_sleep(t_philo *philo, time_t duration)
{
	time_t	end;

	end = get_timestamp() + duration;
	while (get_timestamp() < end)
	{
		if (get_timestamp() - philo->last_eat > philo->vars->t_die)
		{
			philo->vars->must_end = 1;
			print_state(philo, DEAD);
			break ;
		}
		usleep(100);
	}
}
