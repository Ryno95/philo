/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   last_supper.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmeiboom <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/11 14:19:03 by rmeiboom      #+#    #+#                 */
/*   Updated: 2022/01/11 14:26:07 by rmeiboom      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include "defines.h"
#include "ft_time.h"
#include "actions.h"

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

static void	drop_forks(const t_philo *philo)
{
	pthread_mutex_unlock(&philo->left_fork->fork_lock);
	pthread_mutex_unlock(&philo->right_fork->fork_lock);
	philo->left_fork->is_taken = FALSE;
	philo->right_fork->is_taken = FALSE;
}

static t_bool	is_last_supper_over(t_philo *philo)
{
	if (philo->stats->death_has_happened || philo->stats->times_to_eat == 0)
		return (TRUE);
	return (FALSE);
}

void	*last_supper(void *philos)
{
	t_philo	*philo;

	philo = (t_philo *)philos;
	if ((philo->index + 1) % 2 != 0)
		sleep_ms(1);
	while (!is_last_supper_over(philo))
	{
		if (get_forks(philo) && !philo->stats->death_has_happened)
		{
			eat(philo);
			drop_forks(philo);
			if (sleep(philo) == FALSE)
			{
				display_action(get_timestamp(philo), philo, DIE);
				break ;
			}
			think(philo);
		}
	}
	return (NULL);
}
