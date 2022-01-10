/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   handle_threads.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmeiboom <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/06 13:15:49 by rmeiboom      #+#    #+#                 */
/*   Updated: 2022/01/10 13:32:50 by rmeiboom      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include "defines.h"
#include "ft_time.h"
#include "actions.h"

static t_bool	get_forks(const t_philo *philo)
{
	const t_bool has_reached_max_meals = (philo->num_of_meals >= philo->stats->max_meals);
	
	if (has_reached_max_meals)
	{
		// printf("max meals reached %d\n", philo->index);
		return (FALSE);
	}
	if (philo->left_fork->is_taken || philo->right_fork->is_taken)
		return (FALSE);
	philo->left_fork->is_taken = \
	pthread_mutex_lock(&philo->left_fork->fork_lock) == 0;
	printf("philo %d has taken his left fork\n", philo->index);
	philo->right_fork->is_taken = \
		pthread_mutex_lock(&philo->right_fork->fork_lock) == 0;
	printf("philo %d has taken his right fork\n", philo->index);
	return (TRUE);
}

static void	drop_forks(const t_philo *philo)
{
	pthread_mutex_unlock(&philo->left_fork->fork_lock);
	pthread_mutex_unlock(&philo->right_fork->fork_lock);
	philo->left_fork->is_taken = FALSE;
	philo->right_fork->is_taken = FALSE;
}

// while dinner is not over / no one has died && 
// amount of times to eat not reached
// if has both forks 
// 		EAT
// if sleep && philo == DEAD
// 		print death message and break loop
// start_thinking

void	*routine(void *philos)
{
	const t_philo	*philo = (t_philo *)philos;
	int				i;

	i = 0;
	if ((philo->index + 1) % 2 != 0)
		sleep_ms(1);
	while (i < 300000)
	{
		if (get_forks(philo))
		{
			eat(philo);
			drop_forks(philo);
			sleep_ms(philo->stats->tt_sleep);
		}
		++i;
	}
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
