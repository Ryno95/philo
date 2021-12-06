#include "ctest.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../src/parser.h"
#include "../src/philosophers.h"

CTEST_DATA(Philo_creation)
{
	t_fork			*forks;
	t_philo			*philos;
};

CTEST_SETUP(Philo_creation)
{
	data->forks = NULL;
	data->philos = NULL;
}

CTEST_TEARDOWN(Philo_creation)
{
	free(data->forks);
	free(data->philos);
}

CTEST2(Philo_creation, parse_multiple_philos)
{
	t_philo_stats	stats;

	int				i = 0;

	const char *args[] = {"./philos", "3", "10", "1", "1", "4"};
	parse_philo_stats(&args[0], &stats);
	create_philosphers(&stats, &data->forks, &data->philos);
	while (data->philos[i].index == i)
		++i;
	ASSERT_EQUAL(3, i);
	data->philos[0].right_fork->is_taken = TRUE;
	ASSERT_TRUE(data->philos[2].left_fork->is_taken);
	data->philos[0].right_fork->is_taken = FALSE;
	data->philos[1].left_fork->is_taken = TRUE;
	ASSERT_TRUE(data->philos[2].right_fork->is_taken);
	data->philos[1].left_fork->is_taken = FALSE;
	data->philos[1].right_fork->is_taken = TRUE;
	ASSERT_TRUE(data->philos[0].left_fork->is_taken);
}