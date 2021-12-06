#include "ctest.h"
#include <stdlib.h>
#include <stdio.h>
#include "../src/ft_time.h"

static u_int64_t get_time_difference(int wait_time)
{
	const u_int64_t	time = get_timestamp();
	u_int64_t		time_diff;

	sleep_ms(wait_time);
	time_diff = get_timestamp() - time;
	return (time_diff);
}

CTEST(ft_time_tests, custom_sleep)
{
	ASSERT_EQUAL(1, get_time_difference(1));
	ASSERT_EQUAL(0, get_time_difference(0));
	ASSERT_EQUAL(20, get_time_difference(20));
	ASSERT_EQUAL(200, get_time_difference(200));
}
