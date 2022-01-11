/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmeiboom <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/29 13:26:45 by rmeiboom      #+#    #+#                 */
/*   Updated: 2022/01/11 20:24:37 by rmeiboom      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "defines.h"
#include "parser.h"
#include <stdio.h>
#include <stdlib.h>

t_bool	is_valid_input(const int argc, const char *argv[])
{
	(void)argv;
	if (argc != 5 && argc != 6)
		return (FALSE);
	return (TRUE);
}

// Checks that num_str is positive and not decimal
// Bash trims spaces
int	get_number(const char *str)
{
	const int	length = ft_strlen(str);
	int			i;

	i = 0;
	while (i < length && ft_isdigit(str[i]))
		i++;
	if (i != length || !length)
		return (INVALID_NUMBER);
	else
		return (ft_atoi(str));
}

// printf("Please entire only integer values bigger than zero\n");
t_bool	is_valid_stats(t_philo_stats *stats)
{
	if (stats->num_of_philos < 2 || !stats->tt_die || !stats->tt_eat
		|| !stats->tt_sleep || !stats->max_meals || !stats->display)
	{
		printf("%s\n", USAGE_STRING);
		return (FALSE);
	}
	return (TRUE);
}

t_display	*initiate_display(void)
{
	t_display	*disp;

	disp = malloc(sizeof(t_display));
	if (!disp)
		return (NULL);
	disp->is_in_use = FALSE;
	if (pthread_mutex_init(&disp->lock, NULL) != SUCCESS)
	{
		printf("init mutex display lock failed\n");
		return (NULL);
	}
	return (disp);
}

t_exit_status	get_philo_stats(const char *argv[], t_philo_stats *stats)
{
	stats->start_time = get_time_ms();
	stats->num_of_philos = get_number(argv[1]);
	stats->tt_die = get_number(argv[2]);
	stats->tt_eat = get_number(argv[3]);
	stats->tt_sleep = get_number(argv[4]);
	stats->death_has_happened = FALSE;
	stats->display = initiate_display();
	if (argv[5])
		stats->max_meals = get_number(argv[5]);
	else
		stats->max_meals = -1;
	stats->times_to_eat = stats->num_of_philos;
	if (!is_valid_stats(stats))
		return (ERROR);
	return (SUCCESS);
}
