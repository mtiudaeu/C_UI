#pragma once

#include "allocator_cbs.h"

//--------------------------------------------------
// Define structure

struct dyn_buf_info {
 struct allocator_cbs allocator_cbs;
 size_t size;
 size_t capacity;
 size_t size_of_one;
};

#define dyn_buf_define(type)             \
{                                 \
 struct dyn_buf_info dyn_buf_info;\
 type* data;                      \
}

//--------------------------------------------------
// Create
#define DYN_BUF_DEFAULT_CAPACITY 10

#define dyn_buf_create(type)												\
{																			\
 .dyn_buf_info = {															\
  .allocator_cbs=default_allocators,										\
  .size = 0,																\
  .capacity = DYN_BUF_DEFAULT_CAPACITY,															\
  .size_of_one= sizeof(type)												\
 },																			\
 .data=default_allocators.malloc(sizeof(type)*DYN_BUF_DEFAULT_CAPACITY)     \
}

#define dyn_buf_create_1(type, param_capacity)                     \
{                                                                  \
 .dyn_buf_info = {                                                 \
  .allocator_cbs=default_allocators,                               \
  .size = 0,                                                       \
  .capacity = param_capacity,                                      \
  .size_of_one= sizeof(type)                                       \
 },                                                                \
 .data=default_allocators.malloc(sizeof(type)*param_capacity)     \
}

#define dyn_buf_create_2(type, param_capacity, param_allocator_cbs) \
{                                                                   \
 .dyn_buf_info = {                                                  \
  .allocator_cbs=param_allocator_cbs,                               \
  .size = 0,                                                        \
  .capacity = param_capacity,                                       \
  .size_of_one= sizeof(type)                                        \
 },                                                                 \
 .data=param_allocator_cbs.malloc(sizeof(type)*param_capacity)      \
}

//--------------------------------------------------
// Destroy
#define dyn_buf_destroy(dyn_buf)                          \
_dyn_buf_destroy(&((dyn_buf)->dyn_buf_info), (void**)&((dyn_buf)->data))

void _dyn_buf_destroy(struct dyn_buf_info* dyn_buf_info, void** data);

//--------------------------------------------------
// Iterate
#define dyn_buf_begin(dyn_buf) \
dyn_buf.data

#define dyn_buf_end(dyn_buf) \
dyn_buf.data + dyn_buf.dyn_buf_info.size

//--------------------------------------------------
// Add
#define dyn_buf_add(dyn_buf, element)                                    \
do {                                                                      \
 _dyn_buf_ensure_capacity_for_add(&dyn_buf.dyn_buf_info, (void**)&dyn_buf.data);         \
 dyn_buf.data[dyn_buf.dyn_buf_info.size] = element;                    \
 dyn_buf.dyn_buf_info.size++;                                           \
}                                                                         \
while(0)

void _dyn_buf_ensure_capacity_for_add(struct dyn_buf_info* dyn_buf_info, void** data);
//--------------------------------------------------
// Generic comparator

int _dyn_buf_comparator_int(void* lhs, void* rhs);

//--------------------------------------------------
// Find
#define dyn_buf_find_first_idx(dyn_buf, value_ptr) \
	_dyn_buf_find_first_idx(dyn_buf.dyn_buf_info, dyn_buf.data, value_ptr, *dyn_buf.data)

#define _dyn_buf_find_first_idx(dyn_buf_info, data, value_ptr, typed_var)		\
	_dyn_buf_find_first_idx_specific(dyn_buf_info, (void*) data, (void*) value_ptr,	\
	_Generic((typed_var), int: &_dyn_buf_comparator_int) )

int _dyn_buf_find_first_idx_specific(struct dyn_buf_info dyn_buf_info, void* data, void* value_ptr, int (*comparator)(void* lhs, void* rhs));

//--------------------------------------------------
// Sort

#define dyn_buf_sort(dyn_buf) \
 _dyn_buf_sort(dyn_buf.dyn_buf_info, dyn_buf.data, *dyn_buf.data)

#define _dyn_buf_sort(dyn_buf_info, data, typed_var) \
 _dyn_buf_sort_specific(dyn_buf_info, (void*) data,	 \
 _Generic(typed_var, int: &_dyn_buf_comparator_int) )

void _dyn_buf_sort_specific(struct dyn_buf_info dyn_buf_info, void* data, int (*comparator)(void* lhs, void* rhs));

//--------------------------------------------------
/*
void dyn_buf_pop_back(dyn_buf dyn_buf);
void dyn_buf_clear(dyn_buf dyn_buf);

*/
