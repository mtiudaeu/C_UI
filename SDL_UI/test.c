#include "common/test.h"

#include "common/log.h"

#include "test_map.h"
#include "test_dyn_buf.h"


void run_all_test()
{
	LOG_INFO("Starting All Test.")
	test_map_run();
	test_dyn_buf_run();

}