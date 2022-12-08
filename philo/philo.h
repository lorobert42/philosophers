/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorobert <lorobert@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 14:54:02 by lorobert          #+#    #+#             */
/*   Updated: 2022/12/07 15:22:47 by lorobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

enum e_state{thinking, eating, sleeping};

typedef struct s_philo
{
	int	index;
	int	state;
}	t_philo;


typedef struct s_vars
{
	int		n_philo;
	t_philo	*philos;
	int		t_die;
	int		t_eat;
	int		t_sleep;
	int		n_eat;
}	t_vars;

int	ft_atoi(char const *nbr);

#endif
