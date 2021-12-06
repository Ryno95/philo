#include "ctest.h"
#include <stdlib.h>
#include <stdio.h>
#include "../src/ft_time.h"

CTEST(ft_time_tests, custom_sleep)
{
	const int wait_time_ms = 1;
	const uint64_t time = get_timestamp();
	sleep_ms(wait_time_ms);
	uint64_t time_diff = get_timestamp() - time;
	ASSERT_EQUAL(wait_time_ms, time_diff);
}
