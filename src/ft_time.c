/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_time.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmeiboom <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/06 11:19:19 by rmeiboom      #+#    #+#                 */
/*   Updated: 2021/12/06 11:20:32 by rmeiboom      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <sys/time.h>
#include "defines.h"

uint64_t	get_timestamp(void)
{
	const uint64_t	milli_factor = 1000;
	struct timeval	time;
	uint64_t		value;

	gettimeofday(&time, NULL);
	// printf("seconds: %ld\nmicrosec: %d\n", time.tv_sec, time.tv_usec);
	value = (time.tv_sec * milli_factor) + (time.tv_usec / milli_factor);
	// printf("val: %llu\n", value);
	return (value);
}

void	sleep_ms(uint64_t sleep_ms)
{
	const uint64_t	start = get_timestamp();

	while (TRUE)
	{
		if (get_timestamp() - start >= sleep_ms)
			break ;
		usleep(50);
	}
