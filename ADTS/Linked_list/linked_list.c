#include <stdio.h>
#include <stdlib.h>

// Structure for node
struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Insert at beginning
void insert_begin(int data) {

    struct Node* newNode = createNode(data);

    newNode->next = head;  // Point new node to current head
    head = newNode;        // Move head to new node
}

// Insert at end
void insert_end(int data) {

    struct Node* newNode = createNode(data);

    if (head == NULL) {
        head = newNode;
        return;
    }

    struct Node* temp = head;

    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
}

// Insert at specific index
void insert_at_index(int index, int data) {

    if (index == 0) {
        insert_begin(data);
        return;
    }

    struct Node* newNode = createNode(data);
    struct Node* temp = head;

    for (int i = 0; i < index - 1; i++) {
        if (temp == NULL) {
            printf("Invalid index\n");
            return;
        }
        temp = temp->next;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

// Delete first node
void delete_begin() {

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node* temp = head;
    head = head->next;
    free(temp);
}

// Delete last node
void delete_end() {

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    if (head->next == NULL) {
        free(head);
        head = NULL;
        return;
    }

    struct Node* temp = head;

    while (temp->next->next != NULL) {
        temp = temp->next;
    }

    free(temp->next);
    temp->next = NULL;
}


// Delete node at index
void delete_at_index(int index) {

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    if (index == 0) {
        delete_begin();
        return;
    }

    struct Node* temp = head;

    for (int i = 0; i < index - 1; i++) {
        if (temp->next == NULL) {
            printf("Invalid index\n");
            return;
        }
        temp = temp->next;
    }

    struct Node* deleteNode = temp->next;
    temp->next = deleteNode->next;
    free(deleteNode);
}

// Size of list
int size() {

    int count = 0;
    struct Node* temp = head;

    while (temp != NULL) {
        count++;
        temp = temp->next;
    }

    return count;
}

// Clear entire list
void clear() {

    struct Node* temp;

    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

// Display list
void display() {

    struct Node* temp = head;

    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

// Main function
int main() {

    insert_begin(10);
    insert_begin(5);

    insert_end(20);
    insert_end(30);

    insert_at_index(2, 15);

    display();

    delete_begin();
    delete_end();
    delete_at_index(1);

    display();

    printf("Size of list: %d\n", size());

    clear();

    display();

    return 0;
}
