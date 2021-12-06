/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_time.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmeiboom <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/06 11:20:47 by rmeiboom      #+#    #+#                 */
/*   Updated: 2021/12/06 14:22:17 by rmeiboom      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TIME_H
# define FT_TIME_H

#include <stdlib.h>
#include "defines.h"

u_int64_t	get_timestamp(void);
void		sleep_ms(time_ms sleep_ms);

#endif