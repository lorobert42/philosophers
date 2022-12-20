/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorobert <lorobert@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 14:14:46 by lorobert          #+#    #+#             */
/*   Updated: 2022/12/20 14:14:32 by lorobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "philo.h"

void	print_help(void)
{
	printf("Usage: ./philo number_of_philosophers time_to_die time_to_eat \
time_to_sleep [number_of_times_each_philosopher_must_eat]\n");
}

static void	print_log(time_t start, int index, char *str)
{
	printf("%ld %d %s\n", get_timestamp() - start, index, str);
}

void	print_state(t_philo *philo, t_state state)
{
	if (state == THINKING)
		print_log(philo->vars->start, philo->index, "is thinking");
	else if (state == EATING)
		print_log(philo->vars->start, philo->index, "is eating");
	else if (state == SLEEPING)
		print_log(philo->vars->start, philo->index, "is sleeping");
	else if (state == DEAD)
		print_log(philo->vars->start, philo->index, "died");
	else if (state == FORK_L || state == FORK_R)
		print_log(philo->vars->start, philo->index, "has taken a fork");
	else if (state == FORK_L)
		print_log(philo->vars->start, philo->index, "took left fork");
	else if (state == FORK_R)
		print_log(philo->vars->start, philo->index, "took right fork");
}
