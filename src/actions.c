/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   actions.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmeiboom <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/10 11:45:54 by rmeiboom      #+#    #+#                 */
/*   Updated: 2022/01/10 16:14:48 by rmeiboom      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "defines.h"
#include "ft_time.h"
#include <stdio.h>

typedef enum e_action_codes
{
	EAT,
	SLEEP,
	THINK,
	LEFT_FORK,
	RIGHT_FORK,
	DIE
}	t_action_codes;

void	display_action(t_time_ms time, t_philo *philo,
			t_action_codes action_code)
{
	static const char	*actions[] = {
										"is eating",
										"is sleeping",
										"is thinking",
										"has taken left fork",
										"has taken right fork",
										"died"
									};
	while(philo->stats->display->is_in_use && !philo->stats->death_has_happened)
		sleep_ms(1);
	if (!philo->stats->display->is_in_use)
	{
		pthread_mutex_lock(&philo->stats->display->display_lock);
		philo->stats->display->is_in_use = TRUE;
		printf("%llu %d %s\n", time, philo->index, actions[action_code]);
		pthread_mutex_unlock(&philo->stats->display->display_lock);
		if (action_code != DIE)
			philo->stats->display->is_in_use = FALSE;
	}
}

void	eat(t_philo *philo)
{
	const t_time_ms	time_stamp = get_timestamp();

	display_action(time_stamp - philo->stats->start_time, philo, EAT);
	sleep_ms(philo->stats->tt_eat);
	++philo->num_of_meals;
	philo->last_meal = time_stamp;
}

t_bool	sleep(t_philo *philo)
{
	const t_time_ms	time_stamp = get_timestamp() - philo->last_meal;

	if (time_stamp + philo->stats->tt_sleep > philo->stats->tt_die)
	{
		philo->stats->death_has_happened = TRUE;
		display_action(get_timestamp() - philo->stats->start_time, philo, DIE);
		return (FALSE);
	}
	else
	{
		display_action(get_timestamp() - philo->stats->start_time, philo, SLEEP);
		sleep_ms(philo->stats->tt_sleep);
	}
	return TRUE;
}

void	think(t_philo *philo)
{
	const t_time_ms	time_stamp = get_timestamp() - philo->stats->start_time;

	display_action(time_stamp, philo, THINK);
	return ;
}
