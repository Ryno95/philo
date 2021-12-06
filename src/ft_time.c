/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_time.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmeiboom <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/06 11:19:19 by rmeiboom      #+#    #+#                 */
/*   Updated: 2021/12/06 13:01:22 by rmeiboom      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>
#include "defines.h"

u_int64_t	get_timestamp(void)
{
	const u_int64_t	milli_factor = 1000;
	struct timeval	time;
	u_int64_t		value;

	gettimeofday(&time, NULL);
	value = (time.tv_sec * milli_factor) + (time.tv_usec / milli_factor);
	return (value);
}

// only takes a positive number 
void	sleep_ms(u_int64_t sleep_ms)
{
	const u_int64_t	start = get_timestamp();

	while (TRUE)
	{
		if (get_timestamp() - start >= sleep_ms)
			break ;
		usleep(50);
	}
}
