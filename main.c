/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmeiboom <rmeiboom@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/22 10:02:02 by rmeiboom      #+#    #+#                 */
/*   Updated: 2021/11/29 11:01:46 by rmeiboom      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

#define SUCCESS 0
#define ERROR 1

int mails = 0;
pthread_mutex_t mutex;

void routine()
{
	for (int i = 0; i < 1000000; i++)
	{
		pthread_mutex_lock(&mutex);
		++mails;
		pthread_mutex_unlock(&mutex);
	}
	// printf
}

int	create_threads(pthread_t *threads, const int number_of_threads)
{
	int	i;

	i = 0;
	while (i < number_of_threads)
	{
		if (pthread_create(&threads[i], NULL, (void *)&routine, NULL) != SUCCESS)
			return (ERROR);
		++i;
		printf("thread started: %d\n", i);
	}
	return (SUCCESS);
}

int	join_threads(pthread_t *threads, const int number_of_threads)
{
	int	i;

	i = 0;
	while (i < number_of_threads)
	{
		if (pthread_join(threads[i], NULL) != SUCCESS)
			return (ERROR);
		++i;
		printf("thread has finished: %d\n", i);
	}
	return (SUCCESS);
}

int	main(void)
{
	pthread_t threads[4];
	pthread_mutex_init(&mutex, NULL);
	if (create_threads(threads, 4) == ERROR)
		return 2;
	if (join_threads(threads, 4) == ERROR)
		return 3;
	printf("Number of mails: %d\n", mails);
	pthread_mutex_destroy(&mutex);
	return (SUCCESS);
}
