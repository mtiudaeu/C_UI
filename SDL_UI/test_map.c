#include "test_map.h"

#include "common/log.h"
#include "map.h"

void test_map_run() {
    LOG_INFO("test_map Start");

    struct map_int_int map_define(int, int) map = map_create(int, int);

    int key = 1;
    int value = 1;
    map_add(map, &key, &value);



    LOG_INFO("test_map Done");
    /*
    struct map_str_str {
        struct map_node {
            struct str* key;
            struct str* value;
            struct map_node* left;
            struct map_node* right;
        } map_node;
        size_t size;
        struct map_node* head;
    };
    */
}