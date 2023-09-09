#pragma once

#include "test_dyn_buf.h"


#include "common/dyn_buf.h"
#include "common/log.h"

void test_dyn_buf_run()
{
	//mdtmp
	LOG_INFO("test_dyn_buf start");

	struct arr dyn_buf_define(int) test_arr;
	dyn_buf_add(test_arr, 1);
	dyn_buf_add(test_arr, 2);
	dyn_buf_add(test_arr, 3);
	dyn_buf_add(test_arr, 4);

	int should_be_2 = dyn_buf_find_first_idx(test_arr, 2);


}