#pragma once

#include "str.h"

#include <stdio.h>

#define LOG_ERROR(...)                         \
  print_fd(2, "[error] ");                     \
  print_fd(2, __VA_ARGS__);                    \
  print_fd(2, " (%s:%d)", __FILE__, __LINE__); \
  print_fd(2, "\n");

#define LOG_INFO(...)                         \
  print_fd(1, "[info] ");                     \
  print_fd(1, __VA_ARGS__);                    \
  print_fd(1, " (%s:%d)", __FILE__, __LINE__); \
  print_fd(1, "\n");


#ifdef DEBUG_TRACE
#define LOG_TRACE(...)                         \
  print_fd(1, "[trace] ");                     \
  print_fd(1, __VA_ARGS__);                    \
  print_fd(1, " (%s:%d)", __FILE__, __LINE__); \
  print_fd(1, "\n");
#else
#define LOG_TRACE(...) do { } while(0)
#endif

void print(const char* fmt, ...);
void print_fd(int fd, const char* fmt, ...);
