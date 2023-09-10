#pragma once

#include "macros.h"
#include "str.h"
#include "dyn_buf.h"

#define map_define(key_type, value_type)                    \
{                                                           \
    struct key_arr dyn_buf_define(key_type) key_arr;        \
    struct value_arr dyn_buf_define(value_type) value_arr;  \
}

#define map_create(map_ptr) \
dyn_buf_create( &(map_ptr)->key_arr );\
dyn_buf_create( &(map_ptr)->value_arr);

#define map_destroy(map_ptr)\
dyn_buf_destroy( &(map_ptr)->key_arr );\
dyn_buf_destroy( &(map_ptr)->value_arr);

#define map_add(map_ptr, key_ptr, value_ptr) \
{ \
    int VAR_NAME(_found_) = dyn_buf_find_first_idx((map_ptr)->key_arr, key_ptr); \
    if (VAR_NAME(_found_) == -1) \
    { \
        dyn_buf_add((map_ptr)->key_arr, *key_ptr); \
        dyn_buf_add((map_ptr)->value_arr, *value_ptr); \
    } \
    else \
    { \
       (map_ptr)->value_arr.data[ VAR_NAME(_found_) ] = *value_ptr; \
    } \
}

#define map_get(map_ptr, key_ptr, output_ptr_ptr) \
{ \
    int VAR_NAME(_found_) = dyn_buf_find_first_idx((map_ptr)->key_arr, key_ptr); \
    if (VAR_NAME(_found_) == -1) \
    { \
        *output_ptr_ptr = 0x0;\
    } \
    else \
    { \
        *output_ptr_ptr = &(map_ptr)->value_arr.data[ VAR_NAME(_found_) ]; \
    } \
}

/*

#define map_define(key_type, value_type)        \
{                                               \
    struct map_node {                           \
        key_type* key;                          \
        value_type* value;                      \
        struct map_node* left;                  \
        struct map_node* right;                 \
    } * root;                                   \
    size_t size;                                \
    void (*key_copy)(const key_type* key);      \
    void (*key_delete)(key_type* key);          \
    void (*value_copy)(const value_type* key);  \
    void (*value_delete)(value_type* key);      \
};
*/
/*

struct map_node_str_str {
    struct str* key;
    struct str* value;
    struct map_node_str_str* left;
    struct map_node_str_str* right;
};

struct map_str_str {
    size_t size;
    struct map_node_str_str* head;
};

void map_str_str_add(struct map_str_str* map, struct str key, struct str value);
void map_str_str_delete(struct map_str_str* map, struct str key);
struct str map_str_str_get(struct map_str_str* map, struct str key);
void map_str_str_traverse(struct map_str_str* map, int (*callback)(struct str* key, struct str* value));

*/

/*
TreeNode* createNode(int key, int value)
TreeNode* insert(TreeNode* root, int key, int value)

int get(TreeNode* root, int key)
TreeNode* findMin(TreeNode* node)

TreeNode* deleteNode(TreeNode* root, int key)
void inorderTraversal(TreeNode* root)
*/