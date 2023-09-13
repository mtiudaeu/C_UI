#pragma once

#include "allocator_cbs.h"
#include "generic.h"
#include "macros.h"

//--------------------------------------------------
// Generic dynamic buffer that keep type safety.
// Macros are used to keep type safety.

//--------------------------------------------------
// Define structure

struct dyn_buf_info {
 struct allocator_cbs allocator_cbs;
 size_t size;
 size_t capacity;
 size_t size_of_one;
 int (*comparator)(void* lhs, void* rhs);
};

#define dyn_buf_define(type) \
{ \
	type* data; \
	struct dyn_buf_info info;\
	type* (*safe_get)(void*, int, int);\
}
//mdtmp
//mdtmp int* _safe_get_int(void* data, int i);
//mdtmp char* _safe_get_char(void* data, int i);

//--------------------------------------------------
// Create
#define DYN_BUF_DEFAULT_CAPACITY 10

#define dyn_buf_create(dyn_buf)\
(dyn_buf)->info.size_of_one = sizeof(*(dyn_buf)->data);\
(dyn_buf)->info.size= 0;\
(dyn_buf)->info.capacity = DYN_BUF_DEFAULT_CAPACITY;\
(dyn_buf)->info.allocator_cbs = default_allocators;\
(dyn_buf)->info.comparator = generic_comparator(*(dyn_buf)->data);\
(dyn_buf)->data = (dyn_buf)->info.allocator_cbs.malloc((dyn_buf)->info.size_of_one * DYN_BUF_DEFAULT_CAPACITY);\
(dyn_buf)->safe_get = generic_safe_get(*(dyn_buf)->data);

#define dyn_buf_create_2(dyn_buf, capacity)\
(dyn_buf)->info.size_of_one = sizeof(*(dyn_buf)->data);\
(dyn_buf)->info.size= 0;\
(dyn_buf)->info.capacity = capacity;\
(dyn_buf)->info.allocator_cbs = default_allocators;\
(dyn_buf)->info.comparator = generic_comparator(*(dyn_buf)->data);\
(dyn_buf)->data = (dyn_buf)->info.allocator_cbs.malloc((dyn_buf)->info.size_of_one * capacity);


//--------------------------------------------------
// Destroy
#define dyn_buf_destroy(dyn_buf_ptr)                          \
_dyn_buf_destroy(&((dyn_buf_ptr)->info), (void**)&((dyn_buf_ptr)->data))

void _dyn_buf_destroy(struct dyn_buf_info* info, void** data);

//--------------------------------------------------
// Iterate/Get
#define dyn_buf_begin(dyn_buf) \
dyn_buf.data

#define dyn_buf_end(dyn_buf) \
dyn_buf.data + dyn_buf.info.size

#define dyn_buf_get(dyn_buf, i) \
dyn_buf.data[i]

#define dyn_buf_get(dyn_buf, i) \
dyn_buf.data[i]

#define dyn_buf_safe_get(dyn_buf, i) \
dyn_buf.safe_get(dyn_buf.data, dyn_buf.info.size, i)

//--------------------------------------------------
// Add
#define dyn_buf_add(dyn_buf, element)                                    \
do {                                                                      \
 _dyn_buf_ensure_capacity_for_add(&dyn_buf.info, (void**)&dyn_buf.data);         \
 dyn_buf.data[dyn_buf.info.size] = element;                    \
 dyn_buf.info.size++;                                           \
}                                                                         \
while(0)

void _dyn_buf_ensure_capacity_for_add(struct dyn_buf_info* dyn_buf_info, void** data);
//--------------------------------------------------
// Generic comparator

int _dyn_buf_comparator_int(void* lhs, void* rhs);

//--------------------------------------------------
// Find
#define dyn_buf_find_first_idx(dyn_buf, value_ptr) \
	_dyn_buf_find_first_idx(dyn_buf.info, dyn_buf.data, value_ptr)

int _dyn_buf_find_first_idx(struct dyn_buf_info dyn_buf_info, void* data, void* value_ptr);

//--------------------------------------------------
// Sort

#define dyn_buf_sort(dyn_buf) \
 _dyn_buf_sort((dyn_buf)->info, (dyn_buf)->data)

void _dyn_buf_sort(struct dyn_buf_info dyn_buf_info, void* data);

//--------------------------------------------------
/*
void dyn_buf_pop_back(dyn_buf dyn_buf);
void dyn_buf_clear(dyn_buf dyn_buf);

*/
