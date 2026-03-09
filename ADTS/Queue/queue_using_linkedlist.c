#include <stdio.h>
#include <stdlib.h>

// Define structure for a node
struct Node {
    int data;           // Data part
    struct Node* next;  // Pointer to next node
};

// Pointers for front and rear of queue
struct Node* front = NULL;
struct Node* rear = NULL;

// Function to check if queue is empty
int isEmpty() {
    return (front == NULL);
}

// Enqueue operation (Insert element at rear)
void enqueue(int value) {

    // Create a new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    if (newNode == NULL) {
        printf("Queue Overflow! Memory not available\n");
        return;
    }

    newNode->data = value;
    newNode->next = NULL;

    // If queue is empty
    if (rear == NULL) {
        front = rear = newNode;
    }
    else {
        rear->next = newNode;  // Link new node to rear
        rear = newNode;        // Move rear pointer
    }

    printf("%d inserted into queue\n", value);
}

// Dequeue operation (Remove element from front)
int dequeue() {

    if (isEmpty()) {
        printf("Queue Underflow! Queue is empty\n");
        return -1;
    }

    struct Node* temp = front;
    int value = temp->data;

    front = front->next;   // Move front pointer

    // If queue becomes empty
    if (front == NULL)
        rear = NULL;

    free(temp);   // Free removed node

    return value;
}

// Display queue elements
void display() {

    if (isEmpty()) {
        printf("Queue is empty\n");
        return;
    }

    struct Node* temp = front;

    printf("Queue elements are:\n");

    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");
}

// Main function
int main() {

    enqueue(10);
    enqueue(20);
    enqueue(30);

    display();

    printf("Deleted element: %d\n", dequeue());

    display();

    return 0;
}
    