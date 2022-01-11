/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmeiboom <rmeiboom@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/22 10:02:02 by rmeiboom      #+#    #+#                 */
/*   Updated: 2022/01/11 14:29:09 by rmeiboom      ########   odam.nl         */
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
	return (SUCCESS);
}
