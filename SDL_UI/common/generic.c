#include "generic.h"

//--------------------------------------------------
int _generic_comparator_int(void* lhs, void* rhs)
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
int _generic_comparator_char(void* lhs, void* rhs)
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

//--------------------------------------------------
int* _generic_safe_get_int(void* data, int size, int i)
{
	if (i == -1 || i >= size)
		return 0x0;

	int* data_int = (int*)data;
	return &data_int[i];
}
char* _generic_safe_get_char(void* data, int size, int i)
{
	if (i == -1 || i >= size)
		return 0x0;

	int* data_int = (char*)data;
	return &data_int[i];
}