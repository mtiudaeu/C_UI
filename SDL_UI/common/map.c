#include "map.h"

#include "allocator_cbs.h"

#include <stdio.h>
#include <stdlib.h>

/*
//--------------------------------------------------
struct map_node_str_str* _create_node(struct str key, struct str value) {
    struct map_node_str_str* newNode = default_allocators.malloc(sizeof(struct map_node_str_str));
    //mdtmp
    
    //if (newNode) {
    //    newNode->key = key;
    //    newNode->value = value;
    //    newNode->left = NULL;
    //    newNode->right = NULL;
    //}
    
    return newNode;

}

//--------------------------------------------------
void map_str_str_add(struct map_str_str* map, struct str key, struct str value)
{
    struct map_str_str_node;//mdtmp remove
}

//--------------------------------------------------
void map_str_str_delete(struct map_str_str* map, struct str key)
{
}

//--------------------------------------------------
struct str map_str_str_get(struct map_str_str* map, struct str key)
{
}

//--------------------------------------------------
void map_str_str_traverse(struct map_str_str* map, int (*callback)(struct str* key, struct str* value))
{
}

*/
/*

// Function to create a new tree node
TreeNode* createNode(int key, int value) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    if (newNode) {
        newNode->key = key;
        newNode->value = value;
        newNode->left = NULL;
        newNode->right = NULL;
    }
    return newNode;
}

// Function to insert a key-value pair into the BST
TreeNode* insert(TreeNode* root, int key, int value) {
    if (root == NULL) {
        return createNode(key, value);
    }

    if (key < root->key) {
        root->left = insert(root->left, key, value);
    }
    else if (key > root->key) {
        root->right = insert(root->right, key, value);
    }

    return root;
}

// Function to search for a key in the BST and return its value
int get(TreeNode* root, int key) {
    if (root == NULL) {
        return -1; // Key not found
    }

    if (key < root->key) {
        return get(root->left, key);
    }
    else if (key > root->key) {
        return get(root->right, key);
    }
    else {
        return root->value; // Key found, return the associated value
    }
}

// Helper function to find the minimum value node in a BST
TreeNode* findMin(TreeNode* node) {
    while (node->left != NULL) {
        node = node->left;
    }
    return node;
}

// Function to delete a key-value pair from the BST
TreeNode* deleteNode(TreeNode* root, int key) {
    if (root == NULL) {
        return root; // Key not found, return as is
    }

    if (key < root->key) {
        root->left = deleteNode(root->left, key);
    }
    else if (key > root->key) {
        root->right = deleteNode(root->right, key);
    }
    else {
        // Node with the key to be deleted found

        // Case 1: Node with only one child or no child
        if (root->left == NULL) {
            TreeNode* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            TreeNode* temp = root->left;
            free(root);
            return temp;
        }

        // Case 2: Node with two children, get the inorder successor (smallest in the right subtree)
        TreeNode* temp = findMin(root->right);

        // Copy the inorder successor's content to this node
        root->key = temp->key;
        root->value = temp->value;

        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->key);
    }

    return root;
}

// Function to print the BST in-order (sorted order)
void inorderTraversal(TreeNode* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("(%d, %d) ", root->key, root->value);
        inorderTraversal(root->right);
    }
}

int main() {
    TreeNode* root = NULL;

    // Insert key-value pairs into the BST
    root = insert(root, 10, 100);
    root = insert(root, 5, 50);
    root = insert(root, 15, 150);
    root = insert(root, 3, 30);
    root = insert(root, 7, 70);

    // Retrieve values based on keys
    printf("Value for key 10: %d\n", get(root, 10)); // Should print 100
    printf("Value for key 8: %d\n", get(root, 8));   // Should print -1 (key not found)

    // Print the BST in sorted order
    printf("In-order traversal (sorted order): ");
    inorderTraversal(root);
    printf("\n");

    // Delete a node
    root = deleteNode(root, 5);

    // Print the updated BST
    printf("In-order traversal after deleting key 5: ");
    inorderTraversal(root);
    printf("\n");

    // Clean up the tree (free memory)
    free(root);

    return 0;
}
*/