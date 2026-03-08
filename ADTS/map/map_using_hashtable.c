#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

struct Node {
    int key;
    int value;
    struct Node* next;
};

struct Node* hashTable[SIZE];
int count = 0;

// Hash function
int hash(int key) {
    return key % SIZE;
}

// Check if map is empty
int isEmpty() {
    return count == 0;
}

// Insert key-value pair
void insert(int key, int value) {

    int index = hash(key);

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->key = key;
    newNode->value = value;
    newNode->next = hashTable[index];

    hashTable[index] = newNode;
    count++;
}

// Search (lookup)
struct Node* search(int key) {

    int index = hash(key);
    struct Node* temp = hashTable[index];

    while (temp != NULL) {
        if (temp->key == key)
            return temp;
        temp = temp->next;
    }

    return NULL;
}

// Delete key
void delete(int key) {

    int index = hash(key);
    struct Node* temp = hashTable[index];
    struct Node* prev = NULL;

    while (temp != NULL && temp->key != key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
        return;

    if (prev == NULL)
        hashTable[index] = temp->next;
    else
        prev->next = temp->next;

    free(temp);
    count--;
}

// Size of map
int size() {
    return count;
}

// Display map
void display() {

    for (int i = 0; i < SIZE; i++) {
        struct Node* temp = hashTable[i];

        while (temp != NULL) {
            printf("Key: %d Value: %d\n", temp->key, temp->value);
            temp = temp->next;
        }
    }
}

int main() {

    insert(1, 100);
    insert(2, 200);
    insert(12, 300);

    display();

    struct Node* fou*