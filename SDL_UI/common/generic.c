#include "generic.h"

int generic_comparator_int(void* lhs, void* rhs)
{
	int* i_lhs = (int*)lhs;
	int* i_rhs = (int*)rhs;

	if (*i_lhs == *i_rhs) {
		return 0;
	}
	else if (*i_lhs < *i_rhs) {
		return -1;
	}
	return 1;
}

int generic_comparator_char(void* lhs, void* rhs)
{
	char* i_lhs = (char*)lhs;
	char* i_rhs = (char*)rhs;

	if (*i_lhs == *i_rhs) {
		return 0;
	}
	else if (*i_lhs < *i_rhs) {
		return -1;
	}
	return 1;
}