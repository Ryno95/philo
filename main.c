/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmeiboom <rmeiboom@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/22 10:02:02 by rmeiboom      #+#    #+#                 */
/*   Updated: 2022/01/11 13:32:13 by rmeiboom      ########   odam.nl         */
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

void	destroy_fork_mutexes(t_fork *forks, int num_of_forks)
{
	int	i;

	i = 0;
	while (i < num_of_forks)
	{
		pthread_mutex_destroy(&forks[i].fork_lock);
		++i;
	}
}

void	teardown(t_fork *forks, t_philo *philos)
{
	destroy_fork_mutexes(forks, philos->stats->num_of_philos);
	pthread_mutex_destroy(&philos->stats->display->lock);
	free(forks);
	free(philos);
	free(philos->stats->display);
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
	// system("leaks philo");
	return (SUCCESS);
}
