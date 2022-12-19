/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorobert <lorobert@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 14:54:02 by lorobert          #+#    #+#             */
/*   Updated: 2022/12/19 17:55:49 by lorobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>

typedef enum e_state
{
	THINKING = 0,
	EATING = 1,
	SLEEPING = 2,
	DEAD = 3,
	FORK_L = 4,
	FORK_R = 5
}	t_state;

typedef struct s_vars	t_vars;

typedef struct s_philo
{
	int				index;
	time_t			last_eat;
	pthread_mutex_t	*f_left;
	pthread_mutex_t	*f_right;
	pthread_t		thread;
	t_vars			*vars;
}	t_philo;

typedef struct s_vars
{
	time_t			start;
	int				n_philo;
	t_philo			*philos;
	time_t			t_die;
	time_t			t_eat;
	time_t			t_sleep;
	int				n_eat;
	pthread_mutex_t	*forks;
	int				is_dead;
}	t_vars;

void	*philosophy(void *arg);
void	eat_sleep(t_philo *philo);
void	print_state(t_philo *philo, t_state state);
void	ft_sleep(time_t duration);

// conversion
int		ft_atoi(char const *nbr);
time_t	get_timestamp(void);

// printing
void	print_help(void);

// cleaning
void	clean(t_vars *vars);

#endif