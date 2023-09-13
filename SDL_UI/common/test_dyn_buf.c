#pragma once

#include "test_dyn_buf.h"

#include "test.h"


#include "dyn_buf.h"
#include "log.h"

void test_int()
{
	struct arr dyn_buf_define(int) test_arr;
	dyn_buf_create(&test_arr);
	SCOPE(dyn_buf_destroy(&test_arr))
	{
		dyn_buf_add(test_arr, 1);
		dyn_buf_add(test_arr, 2);
		dyn_buf_add(test_arr, 3);
		dyn_buf_add(test_arr, 4);
		dyn_buf_add(test_arr, -1);


		int value = 3;
		int should_be_2 = dyn_buf_find_first_idx(test_arr, &value);
		TEST_ASSERT_TRUE("Find", should_be_2 == 2);

		value = 6;
		int should_be_minus_1 = dyn_buf_find_first_idx(test_arr, &value);
		TEST_ASSERT_TRUE("Don't find", should_be_minus_1 == -1);

		TEST_ASSERT_TRUE("Access", dyn_buf_get(test_arr, 1) == 2);

		TEST_ASSERT_TRUE("Access with invalid support", *dyn_buf_safe_get(test_arr, 1) == 2);
		TEST_ASSERT_TRUE("Access with invalid support", dyn_buf_safe_get(test_arr, -1) == 0x0);


		dyn_buf_sort(&test_arr);
		TEST_ASSERT_TRUE("Sort", dyn_buf_get(test_arr, 0) == -1);
		TEST_ASSERT_TRUE("Sort", dyn_buf_get(test_arr, 1) == 1);
		TEST_ASSERT_TRUE("Sort", dyn_buf_get(test_arr, 2) == 2);
		TEST_ASSERT_TRUE("Sort", dyn_buf_get(test_arr, 3) == 3);
		TEST_ASSERT_TRUE("Sort", dyn_buf_get(test_arr, 4) == 4);
	}
}

void test_char()
{
	struct arr_char dyn_buf_define(char) test_arr;
	dyn_buf_create(&test_arr);
	SCOPE(dyn_buf_destroy(&test_arr))
	{
		dyn_buf_add(test_arr, 'a');
		TEST_ASSERT_TRUE("Access with invalid support", *dyn_buf_safe_get(test_arr, 0) == 'a');
	}
}

void test_dyn_buf_run()
{
	LOG_INFO("test_dyn_buf Start");

	test_int();
	test_char();

	LOG_INFO("test_dyn_buf Done");
}