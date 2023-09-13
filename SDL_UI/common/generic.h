#pragma once

int _generic_comparator_int(void* lhs, void* rhs);
int _generic_comparator_char(void* lhs, void* rhs);
#define generic_comparator(type) _Generic((type),\
	int: &_generic_comparator_int,\
	char: &_generic_comparator_char )

int* _generic_safe_get_int(void* data, int size, int i);
char* _generic_safe_get_char(void* data, int size, int i);
#define generic_safe_get(type) _Generic((type),\
	int:&_generic_safe_get_int,\
	char:&_generic_safe_get_char)