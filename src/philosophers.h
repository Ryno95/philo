/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philosophers.h                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmeiboom <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/01 15:15:50 by rmeiboom      #+#    #+#                 */
/*   Updated: 2021/12/01 15:47:53 by rmeiboom      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include "defines.h"

t_philo			*create_philo_array(t_philo_stats *stats, t_fork *forks);
t_fork			*create_forks(int num_of_forks);
t_exit_status	create_philosphers(t_philo_stats *stats, t_fork **forks,
					t_philo **philos);

#endif