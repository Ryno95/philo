/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmeiboom <rmeiboom@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/22 10:02:02 by rmeiboom      #+#    #+#                 */
/*   Updated: 2022/03/10 13:09:10 by rmeiboom      ########   odam.nl         */
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
	pthread_mutex_destroy(&philos->stats->eat_counter_lock);
	free(forks);
	free(philos);
	free(philos->stats->display);
}

int	run(const char *argv[])
{
	t_philo_stats	stats;
	t_fork			*forks;
	t_philo			*philos;
	pthread_t		threads[MAX_PHILOSOPHERS];
	int				ret;

	forks = NULL;
	philos = NULL;
	if (get_philo_stats(argv, &stats) == ERROR)
		ret = INPUT_ERROR;
	else if (create_philosphers(&stats, &forks, &philos) == ERROR)
		ret = PHILO_CREATION_ERROR;
	else if (create_threads(&threads[0], philos) == ERROR)
		ret = THREAD_CREATION_ERROR;
	else if (join_threads(&threads[0], philos->stats->num_of_philos) == ERROR)
		ret = THREAD_JOINING_ERROR;
	else
		ret = SUCCESS;
	if (ret == SUCCESS || (ret >= 3 && ret <= 5))
		teardown(forks, philos);
	return (ret);
}

int	main(const int argc, const char *argv[])
{
	if (!is_valid_input(argc, argv))
		return (ERROR);
	return (run(argv));
}
