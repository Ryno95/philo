/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmeiboom <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/29 13:26:45 by rmeiboom      #+#    #+#                 */
/*   Updated: 2021/11/29 20:48:34 by rmeiboom      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "defines.h"
#include "parser.h"
#include <stdio.h>

t_bool	is_valid_input(const int argc, const char *argv[])
{
	(void)argv;
	if (argc != 5 && argc != 6)
		return (FALSE);
	return (TRUE);
}

// checks that num_str is positive and not decimal
int	get_number(const char *str)
{
	const int	length = ft_strlen(str);
	int			i;

	i = 0;
	while (i < length && ft_isdigit(str[i]))
		i++;
	if (i != length)
		return (0);
	else
		return (ft_atoi(str));
}

// printf("Please entire only integer values bigger than zero\n");
t_bool	is_valid_stats(t_philo_stats *stats)
{
	if (!stats->num_of_philos || !stats->tt_die || !stats->tt_eat
		|| !stats->tt_sleep || !stats->max_meals)
		return (FALSE);
	return (TRUE);
}

t_exit_status	get_philo_stats(const char *argv[], t_philo_stats *stats)
{
	stats->num_of_philos = get_number(argv[1]);
	stats->tt_die = get_number(argv[2]);
	stats->tt_eat = get_number(argv[3]);
	stats->tt_sleep = get_number(argv[4]);
	if (argv[5])
		stats->max_meals = get_number(argv[5]);
	else
		stats->max_meals = -1;
	if (!is_valid_stats(stats))
		return (ERROR);
	return (SUCCESS);
}

t_exit_status	parse(const char *argv[])
{
	static t_philo_stats	stats;

	if (get_philo_stats(argv, &stats) == ERROR)
		return (3);
	printf("philo_count: %d\n", stats.num_of_philos);
	return (SUCCESS);
}
