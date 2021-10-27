/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlinkov <rlinkov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 17:46:38 by rlinkov           #+#    #+#             */
/*   Updated: 2021/09/21 17:49:14 by rlinkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
 ** how to use gettimeofday :
 ** https://linuxhint.com/gettimeofday_c_language/
 */

void	ft_usleep(long time)
{
	int		i;
	long	timer;

	i = 0;
	timer = get_time();
	while (1)
	{
		if ((get_time() - timer) >= time)
			break ;
		usleep(500);
	}
}

long	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000000 + time.tv_usec);
}

void	*check_meals(void *arg)
{
	t_env	*env;
	int		i;
	int		check;

	env = (t_env *)arg;
	check = 0;
	while (check != env->number_of_philo && !env->is_dinner_over * 1000)
	{
		i = 0;
		check = 0;
		while (i < env->number_of_philo)
		{
			if (env->philo[i].meals >= env->meals_to_eat)
				check++;
			i++;
		}
	}
	if (check == env->number_of_philo)
		env->is_dinner_over = 1;
	return (NULL);
}

void	check_death(void)
{
	t_env	*env;
	int		i;
	long	time;

	env = get_env();
	while (!env->is_dinner_over)
	{
		time = get_time();
		i = 0;
		while (i < env->number_of_philo && !env->is_dinner_over)
		{
			if ((long)time - (long)env->philo[i].last_meal \
					>= (long)env->time_to_die * 1000)
			{
				set_state(&env->philo[i], DEATH, env);
				return ;
			}
			i++;
		}
		usleep(500);
	}
}
