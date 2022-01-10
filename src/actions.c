/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   actions.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmeiboom <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/10 11:45:54 by rmeiboom      #+#    #+#                 */
/*   Updated: 2022/01/10 13:04:48 by rmeiboom      ########   odam.nl         */
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

void display_action(t_time_ms time, int philo_index, t_action_codes action_code)
{
	static const char *actions[] = {
										"is eating",
										"is sleeping",
										"is thinking",
										"has taken left fork",
										"has taken right fork",
										"died"
									};
	printf("%llu %d %s\n", time, philo_index, actions[action_code]);
}

void eat(const t_philo *philo)
{
	const t_time_ms time_stamp = get_timestamp() - philo->stats->start_time;
	display_action(time_stamp, philo->index, EAT);
}