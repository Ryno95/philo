/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   last_supper.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmeiboom <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/11 14:19:03 by rmeiboom      #+#    #+#                 */
/*   Updated: 2022/03/10 12:37:12 by rmeiboom      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include "defines.h"
#include "ft_time.h"
#include "actions.h"
#include <unistd.h>

static t_bool	can_take_fork(t_philo *philo)
{
	if (philo->stats->death_has_happened || \
		philo->left_fork->is_taken || philo->right_fork->is_taken)
		return (FALSE);
	return (TRUE);
}

static t_bool	get_forks(t_philo *philo)
{
	if (!can_take_fork(philo))
		return (FALSE);
	philo->left_fork->is_taken = \
	pthread_mutex_lock(&philo->left_fork->fork_lock) == 0;
	display_action(philo, TAKE_FORK);
	philo->right_fork->is_taken = \
		pthread_mutex_lock(&philo->right_fork->fork_lock) == 0;
	display_action(philo, TAKE_FORK);
	return (TRUE);
}

static t_bool	last_supper_is_over(t_philo *philo)
{
	if (philo->stats->death_has_happened || philo->stats->times_to_eat == 0)
		return (TRUE);
	else if (philo->last_meal + philo->stats->tt_die < get_timestamp(philo))
	{
		display_action(philo, DIE);
		return (TRUE);
	}
	return (FALSE);
}

static void *single_philo_exception(t_philo *philo)
{
	philo->left_fork->is_taken = \
		pthread_mutex_lock(&philo->left_fork->fork_lock) == 0;
	display_action(philo, TAKE_FORK);
	sleep_ms(philo->stats->tt_die);
	display_action(philo, DIE);
	return (NULL);
}

void	*last_supper(void *philos)
{
	t_philo	*philo;

	philo = (t_philo *)philos;
	if (philo->stats->num_of_philos == 1)
		return (single_philo_exception(philo));
	if ((philo->index + 1) % 2 != 0)
		usleep(2000);
	while (!last_supper_is_over(philo))
	{
		usleep(1000);
		if (get_forks(philo) && !philo->stats->death_has_happened)
		{
			eat(philo);
			if (start_sleep(philo) == FALSE)
			{
				display_action(philo, DIE);
				break ;
			}
			think(philo);
		}
	}
	return (NULL);
}
