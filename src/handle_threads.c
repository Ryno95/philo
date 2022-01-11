/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   handle_threads.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmeiboom <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/06 13:15:49 by rmeiboom      #+#    #+#                 */
/*   Updated: 2022/01/11 14:26:45 by rmeiboom      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include "actions.h"
#include "defines.h"
#include "ft_time.h"
#include "last_supper.h"

int	create_threads(pthread_t *threads, t_philo *philos)
{
	const int	num_of_philos = philos->stats->num_of_philos;
	int			i;

	i = 0;
	while (i < num_of_philos)
	{
		if (pthread_create(&threads[i], NULL,
				last_supper, (void *)&philos[i]) != SUCCESS)
			return (ERROR);
		++i;
	}
	return (SUCCESS);
}

int	join_threads(pthread_t *threads, const int number_of_threads)
{
	int	i;

	i = 0;
	while (i < number_of_threads)
	{
		if (pthread_join(threads[i], NULL) != SUCCESS)
			return (ERROR);
		++i;
	}
	return (SUCCESS);
}
