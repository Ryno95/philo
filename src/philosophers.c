/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philosophers.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmeiboom <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/01 15:10:40 by rmeiboom      #+#    #+#                 */
/*   Updated: 2021/12/01 15:38:05 by rmeiboom      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "defines.h"
#include <stdlib.h>
#include <stdio.h>

t_philo	*create_philo_array(t_philo_stats *stats, t_fork *forks)
{
	t_philo			*philosophers;
	unsigned int	i;

	philosophers = malloc(stats->num_of_philos * sizeof(t_philo));
	if (!philosophers)
		return (NULL);
	i = 0;
	while (i < stats->num_of_philos)
	{
		philosophers[i].index = i;
		philosophers[i].stats = stats;
		if (i == 0)
			philosophers[i].right_fork = &forks[stats->num_of_philos - 1];
		else
			philosophers[i].right_fork = &forks[i - 1];
		philosophers[i].left_fork = &forks[i];
		++i;
	}
	return (philosophers);
}

t_fork	*create_forks(int num_of_forks)
{
	t_fork	*forks;
	int		i;

	forks = (t_fork *)malloc(num_of_forks * sizeof(t_fork));
	if (!forks)
		return (NULL);
	i = 0;
	while (i < num_of_forks)
	{
		forks[i].is_taken = FALSE;
		if (pthread_mutex_init(&forks[i].fork_lock, NULL) != SUCCESS)
			printf("init mutex lock failed");
			// return(destroy_forks(forks));
		++i;
	}
	return (forks);
}

t_exit_status	create_philosphers(t_philo_stats *stats, t_fork **forks, t_philo **philos)
{
	*forks = create_forks(stats->num_of_philos);
	if (!*forks)
		return (ERROR);
	*philos = create_philo_array(stats, *forks);
	if (!*philos)
	{
		free(*forks);
		return (ERROR);
	}
	return (SUCCESS);
}