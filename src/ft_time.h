/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_time.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmeiboom <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/06 11:20:47 by rmeiboom      #+#    #+#                 */
/*   Updated: 2022/01/11 14:13:33 by rmeiboom      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TIME_H
# define FT_TIME_H

# include "defines.h"

typedef u_int64_t	t_time_ms;

t_time_ms	get_time_ms(void);
void		sleep_ms(t_time_ms sleep_ms);

#endif