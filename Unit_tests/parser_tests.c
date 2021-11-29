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
