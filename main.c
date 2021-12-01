/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmeiboom <rmeiboom@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/22 10:02:02 by rmeiboom      #+#    #+#                 */
/*   Updated: 2021/12/01 15:52:40 by rmeiboom      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include "src/parser.h"
#include "src/defines.h"
#include "src/philosophers.h"

// int	create_threads(pthread_t *threads, const int number_of_threads)
// {
// 	int	i;

// 	i = 0;
// 	while (i < number_of_threads)
// 	{
// 		if (pthread_create(&threads[i],
//  NULL, (void *)&routine, NULL) != SUCCESS)
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

int	run(const char *argv[])
{
	t_philo_stats	stats;
	t_fork			*forks;
	t_philo			*philos;

	forks = NULL;
	philos = NULL;
	if (parse_philo_stats(argv, &stats) == ERROR)
		return (3);
	if (create_philosphers(&stats, &forks, &philos) != SUCCESS)
	{
		printf("error creating philos\n");
		return (4);
	}
	free(forks);
	free(philos);
	return (SUCCESS);
}

int	main(const int argc, const char *argv[])
{
	if (!is_valid_input(argc, argv))
		return (ERROR);
	if (run(argv) != SUCCESS)
		printf("FUCUP RUNNING\n");
	return (SUCCESS);
}
