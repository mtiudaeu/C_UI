#pragma once

int generic_comparator_int(void* lhs, void* rhs);

#define generic_comparator(type) _Generic((type), int: &generic_comparator_int)