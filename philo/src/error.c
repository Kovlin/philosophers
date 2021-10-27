/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlinkov <rlinkov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 17:34:44 by rlinkov           #+#    #+#             */
/*   Updated: 2021/09/21 17:46:52 by rlinkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_env(void)
{
	t_env	*env;
	int		i;

	env = get_env();
	i = 0;
	if (env->philo)
		free(env->philo);
	if (env->fork)
	{
		while (i < env->number_of_philo && &env->fork[i])
		{
			pthread_mutex_destroy(&env->fork[i]);
			i++;
		}
		free(env->fork);
	}
	pthread_mutex_destroy(&env->print);
}

int	exit_error(char const *str)
{
	printf("%s\n", str);
	free_env();
	return (0);
}
