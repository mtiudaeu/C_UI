#pragma once

#include <stddef.h>
#include <stdlib.h>

struct allocator_cbs {
void* (*malloc) (size_t size); 
void* (*realloc) (void* ptr, size_t size); 
void (*free) (void* ptr); 
};


static const struct allocator_cbs default_allocators =
{
 .malloc = &malloc,
 .realloc = &realloc,
 .free = &free
};