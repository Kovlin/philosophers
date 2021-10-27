/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   status.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlinkov <rlinkov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 17:45:53 by rlinkov           #+#    #+#             */
/*   Updated: 2021/09/17 16:51:51 by rlinkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_state(int state)
{
	if (state == EAT)
		write(1, MSG_EAT, LEN_MSG_EAT);
	else if (state == DEATH)
		write(1, MSG_DEATH, LEN_MSG_DEATH);
	else if (state == THINK)
		write(1, MSG_THINK, LEN_MSG_THINK);
	else if (state == TAKE_FORK)
		write(1, MSG_FORK, LEN_MSG_FORK);
	else if (state == SLEEP)
		write(1, MSG_SLEEP, LEN_MSG_SLEEP);
}

void	set_state(t_philo *philo, int state, t_env *env)
{
	long	i;
	int		j;

	j = 0;
	i = get_time();
	pthread_mutex_lock(&env->print);
	if (env->is_dinner_over)
	{
		pthread_mutex_unlock(&env->print);
		return ;
	}
	ft_putnbr_fd((get_time() - env->start_time) / 1000, 1);
	write(1, " ", 1);
	ft_putnbr_fd(philo->num + 1, 1);
	print_state(state);
	if (state == DEATH)
	{
		env->is_dinner_over = 1;
		while (j++ < env->number_of_philo)
			pthread_mutex_unlock(&env->fork[j]);
		pthread_mutex_unlock(&env->print);
		return ;
	}
	pthread_mutex_unlock(&env->print);
}
