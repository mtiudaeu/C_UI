#pragma once

#include "test_dyn_buf.h"

#include "test.h"


#include "dyn_buf.h"
#include "log.h"

void test_dyn_buf_run()
{
	LOG_INFO("test_dyn_buf Start");

	struct arr dyn_buf_define(int) test_arr = dyn_buf_create(int);
	dyn_buf_add(test_arr, 1);
	dyn_buf_add(test_arr, 2);
	dyn_buf_add(test_arr, 3);
	dyn_buf_add(test_arr, 4);

	struct arr3 dyn_buf_define_2(int);
	struct arr3 tmp;
	dyn_buf_create_5( &tmp );

	int value = 3;
	int should_be_2 = dyn_buf_find_first_idx(test_arr, &value);
	TEST_ASSERT_TRUE("Find", should_be_2 == 2);

	value = 6;
	int should_be_minus_1 = dyn_buf_find_first_idx(test_arr, &value);
	TEST_ASSERT_TRUE("Don't find", should_be_minus_1 == -1);

	LOG_INFO("test_dyn_buf Done");
}