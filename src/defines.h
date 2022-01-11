/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   defines.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmeiboom <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/29 13:25:19 by rmeiboom      #+#    #+#                 */
/*   Updated: 2022/01/11 20:19:55 by rmeiboom      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H
# define FT_INT_MAX 2147483647
# define FT_INT_MIN -2147483648
# define MAX_PHILOSOPHERS 256

# include <pthread.h>
# include <stdlib.h>
# include "ft_time.h"

typedef enum e_exit_status
{
	SUCCESS,
	ERROR,
	INPUT_ERROR,
	PHILO_CREATION_ERROR,
	THREAD_CREATION_ERROR
}	t_exit_status;

typedef enum e_bool
{
	FALSE,
	TRUE
}	t_bool;

typedef struct s_display
{
	pthread_mutex_t	lock;
	t_bool			is_in_use;
}	t_display;

typedef struct s_philo_stats
{
	t_time_ms		start_time;
	unsigned int	num_of_philos;
	unsigned int	tt_die;
	unsigned int	tt_eat;
	unsigned int	tt_think;
	unsigned int	tt_sleep;
	unsigned int	max_meals;
	int				times_to_eat;
	t_bool			death_has_happened;
	t_display		*display;
}	t_philo_stats;

typedef struct s_fork
{
	pthread_mutex_t	fork_lock;
	t_bool			is_taken;
}	t_fork;

typedef struct s_philo
{
	int				index;
	t_philo_stats	*stats;
	t_fork			*left_fork;
	t_fork			*right_fork;
	t_time_ms		last_meal;
	unsigned int	num_of_meals;
}	t_philo;

t_time_ms	get_timestamp(t_philo *philo);

#endif