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
	parse_philo_stats(&args[0], &stats);
	ASSERT_EQUAL(3, stats.num_of_philos);
	ASSERT_EQUAL(10, stats.tt_die);
	ASSERT_EQUAL(1, stats.tt_eat);
	ASSERT_EQUAL(1, stats.tt_sleep);
	ASSERT_EQUAL(4, stats.max_meals);
}

CTEST(Parsing, check_get_num_invalid_nums)
{
	ASSERT_EQUAL(INVALID_NUMBER, get_number("-2"));
	ASSERT_EQUAL(INVALID_NUMBER, get_number("0"));
	ASSERT_EQUAL(INVALID_NUMBER, get_number("2.2"));
	ASSERT_EQUAL(INVALID_NUMBER, get_number(""));
	ASSERT_EQUAL(INVALID_NUMBER, get_number("0.93"));
}

CTEST(Parsing, invalid_num_of_philos)
{
	static t_philo_stats	stats;
	const char *args[] = {"./philos", "-1", "10", "1", "1", "4"};
	ASSERT_EQUAL(ERROR, parse_philo_stats(&args[0], &stats));
}

CTEST(Parsing, invalid_tt_die_decimal)
{
	static t_philo_stats	stats;
	const char *args[] = {"./philos", "1", "1.5", "1", "1", "4"};
	ASSERT_EQUAL(ERROR, parse_philo_stats(&args[0], &stats));
}

CTEST(Parsing, invalid_times_to_eat)
{
	static t_philo_stats	stats;
	const char *args[] = {"./philos", "1", "1", "1", "1", "-4"};
	ASSERT_EQUAL(ERROR, parse_philo_stats(&args[0], &stats));
}

CTEST(Parsing, valid_times_to_eat)
{
	static t_philo_stats	stats;
	const char *args[] = {"./philos", "1", "1", "1", "1", "9"};
	ASSERT_EQUAL(SUCCESS, parse_philo_stats(&args[0], &stats));
	ASSERT_EQUAL(9, stats.max_meals);
}