/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorobert <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 14:14:46 by lorobert          #+#    #+#             */
/*   Updated: 2022/12/22 13:19:41 by lorobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	pthread_mutex_lock(&philo->vars->print_mutex);
	if (state == THINKING && !get_end(philo->vars))
		print_log(philo->vars->start, philo->index, "is thinking");
	else if (state == EATING && !get_end(philo->vars))
		print_log(philo->vars->start, philo->index, "is eating");
	else if (state == SLEEPING && !get_end(philo->vars))
		print_log(philo->vars->start, philo->index, "is sleeping");
	else if (state == DEAD)
		print_log(philo->vars->start, philo->index, "died");
	else if ((state == FORK_L || state == FORK_R) && !get_end(philo->vars))
		print_log(philo->vars->start, philo->index, "has taken a fork");
	else if (state == FORK_L && !get_end(philo->vars))
		print_log(philo->vars->start, philo->index, "took left fork");
	else if (state == FORK_R && !get_end(philo->vars))
		print_log(philo->vars->start, philo->index, "took right fork");
	pthread_mutex_unlock(&philo->vars->print_mutex);
}
