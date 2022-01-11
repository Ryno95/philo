/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   actions.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmeiboom <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/10 11:45:54 by rmeiboom      #+#    #+#                 */
/*   Updated: 2022/01/11 13:58:20 by rmeiboom      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "defines.h"
#include "ft_time.h"
#include <stdio.h>
#include "actions.h"

void	display_action(t_time_ms time, t_philo *philo,
			t_action_codes action_code)
{
	static const char	*actions[] = {
										"is eating",
										"is sleeping",
										"is thinking",
										"has taken a fork",
										"died"
									};

	if (philo->stats->death_has_happened)
		return ;
	while (philo->stats->display->is_in_use && !philo->stats->death_has_happened)
		sleep_ms(1);
	if (!philo->stats->display->is_in_use)
	{
		if (action_code == DIE)
			philo->stats->death_has_happened = TRUE;
		pthread_mutex_lock(&philo->stats->display->lock);
		philo->stats->display->is_in_use = TRUE;
		printf("%4llu %d %s\n", time, philo->index, actions[action_code]);
		pthread_mutex_unlock(&philo->stats->display->lock);
		if (action_code != DIE)
			philo->stats->display->is_in_use = FALSE;
	}

}

void	eat(t_philo *philo)
{
	const t_time_ms	time_stamp = get_timestamp() - philo->stats->start_time;

	if (philo->stats->death_has_happened)
		return ;
	display_action(time_stamp, philo, EAT);
	sleep_ms(philo->stats->tt_eat);
	++philo->num_of_meals;
	if (philo->num_of_meals == philo->stats->max_meals)
		--(philo->stats->times_to_eat);
	philo->last_meal = time_stamp;
}

t_bool	sleep(t_philo *philo)
{
	const t_time_ms	time_stamp = get_timestamp() - philo->stats->start_time;
	const int death_time = philo->last_meal + philo->stats->tt_die;
	const int wake_up_time = time_stamp + philo->stats->tt_sleep;

	if (philo->stats->death_has_happened)
		return (FALSE);
	if (wake_up_time > death_time)
	{
		display_action(get_timestamp() - philo->stats->start_time, philo, SLEEP);
		sleep_ms(death_time - time_stamp);
		return (FALSE);
	}
	display_action(get_timestamp() - philo->stats->start_time, philo, SLEEP);
	sleep_ms(philo->stats->tt_sleep);
	return (TRUE);
}

void	think(t_philo *philo)
{
	const t_time_ms	time_stamp = get_timestamp() - philo->stats->start_time;

	display_action(time_stamp, philo, THINK);
	sleep_ms(2);
	return ;
}
