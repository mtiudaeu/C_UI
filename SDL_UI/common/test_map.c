#include "test_map.h"
#include "test.h"

#include "log.h"
#include "map.h"
#include "macros.h"

void test_map_run() {
    LOG_INFO("test_map Start");
        
    struct map_int_int map_define(int, int) map;
    map_create(&map);
    SCOPE(map_destroy(&map))
    {
        int key = 1;
        int value = 1;
        map_add(&map, &key, &value);

        int* output_ptr;
        map_get(&map, &key, &output_ptr);
        TEST_ASSERT_TRUE("map_get", *output_ptr == 1);

        value = 2;
        map_add(&map, &key, &value);

        map_get(&map, &key, &output_ptr);
        TEST_ASSERT_TRUE("map_get", *output_ptr == 2);

        key = 2;
        map_get(&map, &key, &output_ptr);
        TEST_ASSERT_TRUE("map_get", output_ptr == 0x0);
    }

    LOG_INFO("test_map Done");
}