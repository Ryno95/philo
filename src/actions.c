/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   actions.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmeiboom <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/10 11:45:54 by rmeiboom      #+#    #+#                 */
/*   Updated: 2022/01/12 17:00:37 by rmeiboom      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "defines.h"
#include "ft_time.h"
#include <stdio.h>
#include "actions.h"
#include <unistd.h>

void	display_action(t_time_ms time, t_philo *philo,
			t_action_codes action_code)
{
	static const char	*actions[] = \
	{
		"is eating",
		"is sleeping",
		"is thinking",
		"has taken a fork",
		"died"
	};

	if (philo->stats->death_has_happened)
		return ;
	if (action_code == DIE)
		philo->stats->death_has_happened = TRUE;
	while (philo->stats->display->is_in_use)
		sleep_ms(1);
	if (!philo->stats->display->is_in_use)
	{
		pthread_mutex_lock(&philo->stats->display->lock);
		philo->stats->display->is_in_use = TRUE;
		printf("%llu %d %s\n", time, philo->index, actions[action_code]);
		pthread_mutex_unlock(&philo->stats->display->lock);
		philo->stats->display->is_in_use = FALSE;
	}
}

static void	drop_forks(const t_philo *philo)
{
	pthread_mutex_unlock(&philo->left_fork->fork_lock);
	pthread_mutex_unlock(&philo->right_fork->fork_lock);
	philo->left_fork->is_taken = FALSE;
	philo->right_fork->is_taken = FALSE;
}

void	eat(t_philo *philo)
{
	const t_time_ms	time_stamp = get_timestamp(philo);

	if (philo->stats->death_has_happened)
		return ;
	display_action(time_stamp, philo, EAT);
	sleep_ms(philo->stats->tt_eat);
	drop_forks(philo);
	if (philo->stats->max_meals != -1)
	{
		++philo->num_of_meals;
		if (philo->num_of_meals == philo->stats->max_meals)
		{
			pthread_mutex_lock(&philo->stats->eat_counter_lock);
			--(philo->stats->times_to_eat);
			pthread_mutex_unlock(&philo->stats->eat_counter_lock);
		}
	}
	philo->last_meal = time_stamp;
}

t_bool	start_sleep(t_philo *philo)
{
	const t_time_ms	time_stamp = get_timestamp(philo);
	const int		death_time = philo->last_meal + philo->stats->tt_die;
	const int		wake_up_time = time_stamp + philo->stats->tt_sleep;

	if (philo->stats->death_has_happened)
		return (FALSE);
	if (wake_up_time > death_time)
	{
		display_action(time_stamp, philo, SLEEP);
		sleep_ms(death_time - time_stamp);
		return (FALSE);
	}
	display_action(time_stamp, philo, SLEEP);
	sleep_ms(philo->stats->tt_sleep);
	return (TRUE);
}

void	think(t_philo *philo)
{
	display_action(get_timestamp(philo), philo, THINK);
	sleep_ms(2);
	return ;
}
