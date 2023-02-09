/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorobert <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 15:41:14 by lorobert          #+#    #+#             */
/*   Updated: 2023/02/09 11:42:56 by lorobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_sleep(time_t duration)
{
	time_t	end;

	end = get_timestamp() + duration;
	while (get_timestamp() < end)
	{
		usleep(100);
	}
}
