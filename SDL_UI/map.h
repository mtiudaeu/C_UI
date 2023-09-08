#pragma once

#include "common/str.h"

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


/*
TreeNode* createNode(int key, int value)
TreeNode* insert(TreeNode* root, int key, int value)

int get(TreeNode* root, int key)
TreeNode* findMin(TreeNode* node)

TreeNode* deleteNode(TreeNode* root, int key)
void inorderTraversal(TreeNode* root)
*/