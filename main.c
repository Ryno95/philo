/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmeiboom <rmeiboom@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/22 10:02:02 by rmeiboom      #+#    #+#                 */
/*   Updated: 2021/11/29 10:41:59 by rmeiboom      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

#define SUCCESS 0

int mails = 0;
pthread_mutex_t mutex;

void routine()
{
	for (int i = 0; i < 1000000; i++)
	{
		++mails;
	}
	// printf
}

int	main(void)
{
	pthread_t p1, p2;
	pthread_mutex_init(&mutex, NULL);
	if (pthread_create(&p1, NULL, (void *)&routine, NULL) != SUCCESS)
		return (1);
	if (pthread_create(&p2, NULL, (void *)&routine, NULL) != SUCCESS)
		return (2);
	if (pthread_join(p1, NULL) != SUCCESS)
		return (3);
	if (pthread_join(p2, NULL) != SUCCESS)
		return (4);
	printf("Number of mails: %d\n", mails);
	pthread_mutex_destroy(&mutex);
	return (SUCCESS);
}
