#include "ctest.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../src/parser.h"

CTEST(Parsing, check_is_valid_input)
{
	ASSERT_EQUAL(FALSE, is_valid_input(1, NULL));
	ASSERT_EQUAL(TRUE, is_valid_input(5, NULL));
	ASSERT_EQUAL(TRUE, is_valid_input(6, NULL));
}

CTEST(Parsing, assign_valid_philo_stats)
{
	static t_philo_stats	stats;
	const char *args[] = {"./philos", "3", "10", "1", "1", "4"};
	get_philo_stats(&args[0], &stats);
	ASSERT_EQUAL(3, stats.num_of_philos);
	ASSERT_EQUAL(10, stats.tt_die);
	ASSERT_EQUAL(1, stats.tt_eat);
	ASSERT_EQUAL(1, stats.tt_sleep);
	ASSERT_EQUAL(4, stats.max_meals);
}
