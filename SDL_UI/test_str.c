#include "test_str.h"

#include "common/macros.h"
#include "common/str.h"

void test_str()
{
	struct str_buf test1 = str_buf_create(10);
	SCOPE(str_buf_destroy(&test1));


}