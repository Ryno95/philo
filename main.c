/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmeiboom <rmeiboom@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/22 10:02:02 by rmeiboom      #+#    #+#                 */
/*   Updated: 2021/12/06 13:20:03 by rmeiboom      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include "src/defines.h"
#include "src/handle_threads.h"
#include "src/parser.h"
#include "src/philosophers.h"
#include "src/ft_time.h"

// void	*routine(void *philos)
// {
// 	const t_philo	*philo = (t_philo *)philos;

// 	printf("philo number: %d\n", philo->index + 1);
// 	return (NULL);
// }

// int	create_threads(pthread_t *threads, t_philo *philos)
// {
// 	const int	num_of_philos = philos->stats->num_of_philos;
// 	int			i;

// 	i = 0;
// 	while (i < num_of_philos)
// 	{
// 		if (pthread_create(&threads[i], NULL,
// 				routine, (void *)&philos[i]) != SUCCESS)
// 			return (ERROR);
// 		++i;
// 		printf("thread started: %d\n", i);
// 	}
// 	return (SUCCESS);
// }

// int	join_threads(pthread_t *threads, const int number_of_threads)
// {
// 	int	i;

// 	i = 0;
// 	while (i < number_of_threads)
// 	{
// 		if (pthread_join(threads[i], NULL) != SUCCESS)
// 			return (ERROR);
// 		++i;
// 		printf("thread has finished: %d\n", i);
// 	}
// 	return (SUCCESS);
// }

void	teardown(t_fork *forks, t_philo *philos)
{
	free(forks);
	free(philos);
}

int	run(const char *argv[])
{
	t_philo_stats	stats;
	t_fork			*forks;
	t_philo			*philos;
	pthread_t		threads[1024];

	forks = NULL;
	philos = NULL;
	if (parse_philo_stats(argv, &stats) == ERROR)
		return (3);
	if (create_philosphers(&stats, &forks, &philos) != SUCCESS)
	{
		printf("error creating philos\n");
		return (4);
	}
	create_threads(&threads[0], philos);
	join_threads(&threads[0], philos->stats->num_of_philos);
	teardown(forks, philos);
	return (SUCCESS);
}

int	main(const int argc, const char *argv[])
{
	if (!is_valid_input(argc, argv))
		return (ERROR);
	if (run(argv) != SUCCESS)
		printf("FUCKUP RUNNING\n");
	return (SUCCESS);
}
