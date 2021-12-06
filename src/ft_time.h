/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_time.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmeiboom <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/06 11:20:47 by rmeiboom      #+#    #+#                 */
/*   Updated: 2021/12/06 14:25:06 by rmeiboom      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TIME_H
# define FT_TIME_H

#	include "defines.h"

t_time_ms	get_timestamp(void);
void		sleep_ms(t_time_ms sleep_ms);

#endif