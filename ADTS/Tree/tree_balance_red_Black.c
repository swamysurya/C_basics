#include <stdio.h>
#include <stdlib.h>

enum Color {RED, BLACK};

struct Node {
    int data;
    int color;
    struct Node *left, *right, *parent;
};

struct Node* root = NULL;

struct Node* createNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = node->parent = NULL;
    node->color = RED;
    return node;
}

void leftRotate(struct Node* x) {

    struct Node* y = x->right;
    x->right = y->left;

    if (y->left != NULL)
        y->left->parent = x;

    y->parent = x->parent;

    if (x->parent == NULL)
        root = y;
    else if (x == x->parent->left)
        x->parent->left = y;
    else
        x->parent->right = y;

    y->left = x;
    x->parent = y;
}

void rightRotate(struct Node* y) {

    struct Node* x = y->left;
    y->left = x->right;

    if (x->right != NULL)
        x->right->parent = y;

    x->parent = y->parent;

    if (y->parent == NULL)
        root = x;
    else if (y == y->parent->left)
        y->parent->left = x;
    else
        y->parent->right = x;

    x->right = y;
    y->parent = x;
}

void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void insert(int data) {

    struct Node* node = createNode(data);
    struct Node* y = NULL;
    struct Node* x = root;

    while (x != NULL) {
        y = x;
        if (node->data < x->data)
            x = x->left;
        else
            x = x->right;
    }

    node->parent = y;

    if (y == NULL)
        root = node;
    else if (node->data < y->data)
        y->left = node;
    else
        y->right = node;

    node->color = RED;
}

int main() {

    insert(10);
    insert(20);
    insert(30);
    insert(15);
    insert(25);

    printf("Inorder Traversal: ");
    inorder(root);

    return 0;
}
