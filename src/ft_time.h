/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_time.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmeiboom <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/06 11:20:47 by rmeiboom      #+#    #+#                 */
/*   Updated: 2021/12/06 14:00:20 by rmeiboom      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TIME_H
# define FT_TIME_H

#include <stdlib.h>

u_int64_t	get_timestamp(void);
void		sleep_ms(u_int64_t sleep_ms);

#endif