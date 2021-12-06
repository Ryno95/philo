/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   handle_threads.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmeiboom <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/06 13:15:49 by rmeiboom      #+#    #+#                 */
/*   Updated: 2021/12/06 13:16:13 by rmeiboom      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdio.h>
#include "defines.h"

void	*routine(void *philos)
{
	const t_philo	*philo = (t_philo *)philos;

	printf("philo number: %d\n", philo->index + 1);
	return (NULL);
}

int	create_threads(pthread_t *threads, t_philo *philos)
{
	const int	num_of_philos = philos->stats->num_of_philos;
	int			i;

	i = 0;
	while (i < num_of_philos)
	{
		if (pthread_create(&threads[i], NULL,
				routine, (void *)&philos[i]) != SUCCESS)
			return (ERROR);
		++i;
		printf("thread started: %d\n", i);
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
		printf("thread has finished: %d\n", i);
	}
	return (SUCCESS);
}