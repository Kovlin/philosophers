/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlinkov <rlinkov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 15:23:43 by rlinkov           #+#    #+#             */
/*   Updated: 2021/09/21 17:04:42 by rlinkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eating(t_philo *philo)
{
	t_env	*env;

	env = get_env();
	take_fork(philo);
	philo->last_meal = get_time();
	set_state(philo, EAT, env);
	ft_usleep(env->time_to_eat * 1000);
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
	philo->meals++;
	set_state(philo, SLEEP, env);
	ft_usleep(env->time_to_sleep * 1000);
	set_state(philo, THINK, env);
}

void	take_fork(t_philo *philo)
{
	t_env	*env;

	env = get_env();
	pthread_mutex_lock(philo->l_fork);
	set_state(philo, TAKE_FORK, env);
	pthread_mutex_lock(philo->r_fork);
	set_state(philo, TAKE_FORK, env);
}
