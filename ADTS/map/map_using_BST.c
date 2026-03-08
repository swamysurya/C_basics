#include <stdio.h>
#include <stdlib.h>

// Node structure for Map
struct Node {
    int key;
    int value;
    struct Node* left;
    struct Node* right;
};

int count = 0;   // Number of key-value pairs

// Create new node
struct Node* createNode(int key, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->key = key;
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

// Insert key-value pair
struct Node* insert(struct Node* root, int key, int value) {

    if (root == NULL) {
        count++;
        return createNode(key, value);
    }

    if (key < root->key)
        root->left = insert(root->left, key, value);

    else if (key > root->key)
        root->right = insert(root->right, key, value);

    return root;
}

// Search (lookup)
struct Node* search(struct Node* root, int key) {

    if (root == NULL || root->key == key)
        return root;

    if (key < root->key)
        return search(root->left, key);
    else
        return search(root->right, key);
}

// Find minimum node
struct Node* findMin(struct Node* root) {

    while (root->left != NULL)
        root = root->left;

    return root;
}

// Delete key
struct Node* deleteNode(struct Node* root, int key) {

    if (root == NULL)
        return root;

    if (key < root->key)
        root->left = deleteNode(root->left, key);

    else if (key > root->key)
        root->right = deleteNode(root->right, key);

    else {

        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            count--;
            return temp;
        }

        else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            count--;
            return temp;
        }

        struct Node* temp = findMin(root->right);

        root->key = temp->key;
        root->value = temp->value;

        root->right = deleteNode(root->right, temp->key);
    }

    return root;
}

// Check if map is empty
int isEmpty() {
    return count == 0;
}

// Return number of elements
int size() {
    return count;
}

// Traversal (display map)
void inorder(struct Node* root) {

    if (root != NULL) {
        inorder(root->left);
        printf("Key: %d Value: %d\n", root->key, root->value);
        inorder(root->right);
    }
}

int main() {

    struct Node* root = NULL;

    root = insert(root, 10, 100);
    insert(root, 20, 200);
    insert(root, 5, 50);
    insert(root, 15, 150);

    printf("Map elements:\n");
    inorder(root);

    struct Node* found = search(root, 20);

    if (found)
        printf("Found value: %d\n", found->value);
    else
        printf("Key not found\n");

    root = deleteNode(root, 10);

    printf("\nAfter deletion:\n");
    inorder(root);

    printf("\nSize of map: %d\n", size());

    if (isEmpty())
        printf("Map is empty\n");
    else
        printf("Map is not empty\n");

    return 0;
}
