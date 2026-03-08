#include <stdio.h>
#include <stdlib.h>

// Define structure for a node
struct Node {
    int data;           // Data part
    struct Node* next;  // Pointer to next node
};

// Top pointer of stack
struct Node* top = NULL;

// Function to check if stack is empty
int isEmpty() {
    return (top == NULL);
}

// Push operation (Insert element into stack)
void push(int value) {

    // Create new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    if (newNode == NULL) {
        printf("Stack Overflow! Memory not available\n");
        return;
    }

    newNode->data = value;  // Assign value to node
    newNode->next = top;    // Link new node to previous top
    top = newNode;          // Move top to new node

    printf("%d pushed into stack\n", value);
}

// Pop operation (Remove top element)
int pop() {

    if (isEmpty()) {
        printf("Stack Underflow! Stack is empty\n");
        return -1;
    }

    struct Node* temp = top;  // Store current top
    int value = temp->data;   // Get value

    top = top->next;          // Move top to next node
    free(temp);               // Free removed node

    return value;
}

// Peek operation (View top element)
int peek() {

    if (isEmpty()) {
        printf("Stack is empty\n");
        return -1;
    }

    return top->data;
}

// Display stack elements
void display() {

    if (isEmpty()) {
        printf("Stack is empty\n");
        return;
    }

    struct Node* temp = top;

    printf("Stack elements are:\n");

    while (temp != NULL) {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}

// Main function
int main() {

    push(10);
    push(20);
    push(30);

    display();

    printf("Top element is: %d\n", peek());

    printf("Popped element: %d\n", pop());

    display();

    return 0;
}
