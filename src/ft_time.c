/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_time.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmeiboom <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/06 11:19:19 by rmeiboom      #+#    #+#                 */
/*   Updated: 2021/12/06 11:39:11 by rmeiboom      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>
#include "defines.h"

uint64_t	get_timestamp(void)
{
	const uint64_t	milli_factor = 1000;
	struct timeval	time;
	uint64_t		value;

	gettimeofday(&time, NULL);
	value = (time.tv_sec * milli_factor) + (time.tv_usec / milli_factor);
	return (value);
}

// only takes a positive number 
void	sleep_ms(uint64_t sleep_ms)
{
	const uint64_t	start = get_timestamp();

	while (TRUE)
	{
		if (get_timestamp() - start >= sleep_ms)
			break ;
		usleep(50);
	}
}
