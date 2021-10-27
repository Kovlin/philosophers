/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlinkov <rlinkov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 17:27:50 by rlinkov           #+#    #+#             */
/*   Updated: 2021/09/15 17:44:56 by rlinkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
 ** Functions that initialize the environement with the threads and mutexes
 */

void	init_philo(void)
{
	t_env	*env;
	int		i;

	env = get_env();
	i = 0;
	while (i < env->number_of_philo)
	{
		env->philo[i].num = i;
		env->philo[i].meals = 0;
		env->philo[i].last_meal = get_time();
		env->philo[i].state = THINK;
		env->philo[i].l_fork = &env->fork[i];
		env->philo[i].r_fork = &env->fork[(i + 1) % env->number_of_philo];
		i++;
	}
}

int	init(void)
{
	t_env	*env;
	int		i;

	env = get_env();
	env->philo = malloc(env->number_of_philo * sizeof(t_philo));
	if (!env->philo)
		return (exit_error("Malloc failure while allocating the philosophers"));
	env->fork = malloc(env->number_of_philo * sizeof(pthread_mutex_t));
	if (!env->fork)
		return (exit_error("Malloc failure while allocating the fork"));
	i = 0;
	while (i < env->number_of_philo)
	{
		if (pthread_mutex_init(&env->fork[i], NULL))
			return (exit_error("Mutex init error"));
		i++;
	}
	init_philo();
	if (pthread_mutex_init(&env->print, NULL))
		return (exit_error("Mutex init error"));
	return (1);
}
