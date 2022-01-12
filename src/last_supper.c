/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   last_supper.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmeiboom <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/11 14:19:03 by rmeiboom      #+#    #+#                 */
/*   Updated: 2022/01/12 16:12:39 by rmeiboom      ########   odam.nl         */
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
	if (philo->left_fork->is_taken || philo->right_fork->is_taken
		|| philo->stats->death_has_happened)
		return (FALSE);
	return (TRUE);
}

static t_bool	get_forks(t_philo *philo)
{
	const int	time_stamp = get_timestamp(philo);

	if (!can_take_fork(philo))
		return (FALSE);
	philo->left_fork->is_taken = \
	pthread_mutex_lock(&philo->left_fork->fork_lock) == 0;
	philo->right_fork->is_taken = \
		pthread_mutex_lock(&philo->right_fork->fork_lock) == 0;
	display_action(time_stamp, philo, TAKE_FORK);
	display_action(time_stamp, philo, TAKE_FORK);
	return (TRUE);
}

static t_bool	last_supper_is_over(t_philo *philo)
{
	if (philo->stats->death_has_happened || philo->stats->times_to_eat == 0)
		return (TRUE);
	else if (philo->last_meal + philo->stats->tt_die < get_timestamp(philo))
	{
		display_action(get_timestamp(philo), philo, DIE);
		return (TRUE);
	}
	return (FALSE);
}

void	*last_supper(void *philos)
{
	t_philo	*philo;

	philo = (t_philo *)philos;
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
				display_action(get_timestamp(philo), philo, DIE);
				break ;
			}
			think(philo);
		}
	}
	return (NULL);
}
