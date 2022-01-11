/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   actions.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmeiboom <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/10 11:45:48 by rmeiboom      #+#    #+#                 */
/*   Updated: 2022/01/11 12:40:57 by rmeiboom      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ACTIONS_H
# define ACTIONS_H

# include "defines.h"

typedef enum e_action_codes
{
	EAT,
	SLEEP,
	THINK,
	TAKE_FORK,
	DIE
}	t_action_codes;

void	display_action(t_time_ms time, t_philo *philo,
			t_action_codes action_code);
void	eat(t_philo *philo);
t_bool	sleep(t_philo *philo);
void	think(t_philo *philo);

#endif