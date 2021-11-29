/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   defines.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmeiboom <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/29 13:25:19 by rmeiboom      #+#    #+#                 */
/*   Updated: 2021/11/29 19:41:35 by rmeiboom      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H
# define FT_INT_MAX 2147483647
# define FT_INT_MIN -2147483648
# define MAX_PHILOSOPHERS 1024

typedef enum e_exit_status
{
	SUCCESS,
	ERROR
}	t_exit_status;

typedef enum e_bool
{
	FALSE,
	TRUE
}	t_bool;

typedef struct s_philo_stats
{
	unsigned int	num_of_philos;
	unsigned int	tt_die;
	unsigned int	tt_eat;
	unsigned int	tt_sleep;
	unsigned int	max_meals;
}	t_philo_stats;

typedef struct s_philo
{
	int				index;
	t_philo_stats	*stats;
}	t_philo;

#endif