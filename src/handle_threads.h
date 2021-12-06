/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   handle_threads.h                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmeiboom <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/06 13:17:07 by rmeiboom      #+#    #+#                 */
/*   Updated: 2021/12/06 13:18:12 by rmeiboom      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef HANDLE_THREADS_H
# define HANDLE_THREADS_H

# include <pthread.h>
# include "defines.h"

void	*routine(void *philos);
int		create_threads(pthread_t *threads, t_philo *philos);
int		join_threads(pthread_t *threads, const int number_of_threads);

#endif