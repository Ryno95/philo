/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   handle_threads.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmeiboom <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/06 13:15:49 by rmeiboom      #+#    #+#                 */
/*   Updated: 2022/01/11 13:53:56 by rmeiboom      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include "defines.h"
#include "ft_time.h"
#include "actions.h"

static t_bool	get_forks(t_philo *philo)
{
	const int time_stamp = get_timestamp() - philo->stats->start_time;

	if (philo->left_fork->is_taken || philo->right_fork->is_taken || philo->stats->death_has_happened)
		return (FALSE);
	philo->left_fork->is_taken = \
	pthread_mutex_lock(&philo->left_fork->fork_lock) == 0;
	philo->right_fork->is_taken = \
		pthread_mutex_lock(&philo->right_fork->fork_lock) == 0;
	display_action(time_stamp, philo, TAKE_FORK);
	display_action(time_stamp, philo, TAKE_FORK);
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

t_bool	is_dinner_over(t_philo *philo)
{
	if (philo->stats->death_has_happened || philo->stats->times_to_eat == 0)
		return (TRUE);
	return (FALSE);
}

void	*routine(void *philos)
{
	t_philo	*philo;

	philo = (t_philo *)philos;
	if ((philo->index + 1) % 2 != 0)
		sleep_ms(1);
	while (!is_dinner_over(philo))
	{
		if (get_forks(philo) && !philo->stats->death_has_happened)
		{
			eat(philo);
			drop_forks(philo);
			if (sleep(philo) == FALSE)
			{
				display_action(get_timestamp() - philo->stats->start_time, philo, DIE);
				break ;
			}
			think(philo);
		}
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
