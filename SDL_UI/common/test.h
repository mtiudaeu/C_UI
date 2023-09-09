#pragma once

#include "log.h"

#include <stdio.h>
#include <assert.h>

#define TEST_ASSERT_MSG(test_title, msg)                                   \
  LOG_ERROR("Test Error : %s, %s\n", msg); \
  assert(0);                                               \

#define TEST_ASSERT_TRUE(test_title, expr)                                     \
  if (expr) {                                                      \
    LOG_INFO("Test Success : %s\n", test_title);                                      \
  } else {                                                         \
    LOG_ERROR("Test Error : %s, %s\n", test_title, #expr ); \
    assert(0);                                                 \
  }

void run_all_test();