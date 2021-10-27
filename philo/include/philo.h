/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlinkov <rlinkov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 14:34:38 by rlinkov           #+#    #+#             */
/*   Updated: 2021/09/21 17:51:22 by rlinkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

/*
** Constant used to set the state of the philosophers
*/

# define EAT 1
# define TAKE_FORK 2
# define SLEEP 3
# define THINK 4
# define DEATH 5
# define MSG_EAT " is eating\n"
# define MSG_FORK " has taken a fork\n"
# define MSG_SLEEP " is sleeping\n"
# define MSG_THINK " is thinking\n"
# define MSG_DEATH " died\n"
# define LEN_MSG_EAT 12
# define LEN_MSG_FORK 19
# define LEN_MSG_SLEEP 14
# define LEN_MSG_THINK 14
# define LEN_MSG_DEATH 7
/*
** Structures used for the philosopher program
*/

typedef struct s_philo
{
	int				num;
	int				state;
	int				meals;
	long			last_meal;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*r_fork;
	pthread_t		thread;
}				t_philo;

typedef struct s_env
{
	int				number_of_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				meals_to_eat;
	int				is_dinner_over;
	long			start_time;
	pthread_mutex_t	*fork;
	t_philo			*philo;
	pthread_mutex_t	print;
}				t_env;

/*
** Functions for the philosopher program
*/

t_env	*get_env(void);
int		check_input(int ac, char **av);
int		init(void);
int		exit_error(char const *str);
void	free_env(void);
void	eating(t_philo *philo);
void	take_fork(t_philo *philo);
void	set_state(t_philo *philo, int state, t_env *env);
void	print_state(int state);
void	*check_meals(void *arg);
void	check_death(void);
long	get_time(void);
void	ft_usleep(long sleep_time);
int		ft_atoi(const char *str);
void	ft_putchar_fd(char c, int fd);
void	ft_putnbr_fd(int n, int fd);

#endif