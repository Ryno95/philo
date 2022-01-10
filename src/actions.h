/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   actions.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmeiboom <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/10 11:45:48 by rmeiboom      #+#    #+#                 */
/*   Updated: 2022/01/10 15:55:18 by rmeiboom      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ACTIONS_H
# define ACTIONS_H

# include "defines.h"

void	eat(t_philo *philo);
t_bool	sleep(t_philo *philo);
void	think(t_philo *philo);

#endif