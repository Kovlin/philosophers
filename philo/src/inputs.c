/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlinkov <rlinkov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 17:34:27 by rlinkov           #+#    #+#             */
/*   Updated: 2021/09/21 16:55:19 by rlinkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	fill_input(int ac, char **av)
{
	t_env	*env;

	env = get_env();
	env->number_of_philo = ft_atoi(av[1]);
	env->time_to_die = ft_atoi(av[2]);
	env->time_to_eat = ft_atoi(av[3]);
	env->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		env->meals_to_eat = ft_atoi(av[5]);
	else
		env->meals_to_eat = -1;
	env->is_dinner_over = 0;
	return (0);
}

int	check_input(int ac, char **av)
{
	if (ac != 5 && ac != 6)
	{
		printf("Error : 4 or 5 arguments needed\n");
		return (1);
	}
	if (ft_atoi(av[1]) < 1)
	{
		printf("Error : invalid argument\n");
		return (1);
	}
	if (ft_atoi(av[2]) < 1 || ft_atoi(av[3]) < 1 || ft_atoi(av[4]) < 1)
	{
		printf("Error : invalid argument\n");
		return (1);
	}
	if (ac == 6)
	{
		if (ft_atoi(av[5]) < 0)
		{
			printf("Error : invalid argument\n");
			return (1);
		}
	}
	return (fill_input(ac, av));
}
