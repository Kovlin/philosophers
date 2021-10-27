/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlinkov <rlinkov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 14:31:34 by rlinkov           #+#    #+#             */
/*   Updated: 2021/09/21 17:45:43 by rlinkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_env	*get_env(void)
{
	static t_env	env;

	return (&env);
}

void	*routine(void *arg)
{
	t_env	*env;
	t_philo	*philo;

	philo = (t_philo *)arg;
	env = get_env();
	while (!env->is_dinner_over)
		eating(philo);
	return (NULL);
}

void	start(void)
{
	t_env		*env;
	int			i;
	pthread_t	th;

	env = get_env();
	i = 0;
	env->start_time = get_time();
	while (i < env->number_of_philo)
	{
		pthread_create(&env->philo[i].thread, NULL, &routine,
			(void*)&env->philo[i]);
		i += 2;
		usleep(20);
	}
	usleep(100);
	i = 1;
	while (i < env->number_of_philo)
	{
		pthread_create(&env->philo[i].thread, NULL, &routine,
			(void*)&env->philo[i]);
		i += 2;
		usleep(20);
	}
	if (env->meals_to_eat != -1)
		pthread_create(&th, NULL, &check_meals, (void *)env);
}

int	main(int argc, char **argv)
{
	t_env	*env;
	int		i;

	env = get_env();
	if (check_input(argc, argv))
		return (1);
	if (!init())
		return (1);
	start();
	check_death();
	i = 0;
	while (i < env->number_of_philo && env->number_of_philo > 1)
	{
		pthread_join(env->philo[i].thread, NULL);
		i++;
	}
	free_env();
	return (0);
}
