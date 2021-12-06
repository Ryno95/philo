/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_time.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmeiboom <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/06 11:19:19 by rmeiboom      #+#    #+#                 */
/*   Updated: 2021/12/06 14:25:34 by rmeiboom      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

// #include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>
#include "defines.h"

t_time_ms	get_timestamp(void)
{
	const t_time_ms	milli_factor = 1000;
	struct timeval	time;
	t_time_ms		value;

	gettimeofday(&time, NULL);
	value = (time.tv_sec * milli_factor) + (time.tv_usec / milli_factor);
	return (value);
}

// only takes a positive number 
void	sleep_ms(t_time_ms sleep_ms)
{
	const t_time_ms	start = get_timestamp();

	while (TRUE)
	{
		if (get_timestamp() - start >= sleep_ms)
			break ;
		usleep(50);
	}
}
