#include <stdio.h>

#define MAX 5   // Maximum size of the stack

// Declare stack array
int stack[MAX];

// Top pointer of stack
int top = -1;

// Function to check if stack is full
int isFull() {
    return (top == MAX - 1);
}

// Function to check if stack is empty
int isEmpty() {
    return (top == -1);
}

// Push operation (insert element)
void push(int value) {
    if (isFull()) {
        printf("Stack Overflow! Cannot insert %d\n", value);
        return;
    }

    top++;                 // Move top pointer
    stack[top] = value;    // Insert element
    printf("%d pushed into stack\n", value);
}

// Pop operation (remove element)
int pop() {
    if (isEmpty()) {
        printf("Stack Underflow! Stack is empty\n");
        return -1;
    }

    int value = stack[top];  // Get top element
    top--;                   // Decrease top pointer
    return value;
}

// Peek operation (view top element)
int peek() {
    if (isEmpty()) {
        printf("Stack is empty\n");
        return -1;
    }

    return stack[top];
}

// Display stack elements
void display() {
    if (isEmpty()) {
        printf("Stack is empty\n");
        return;
    }

    printf("Stack elements are:\n");

    for (int i = top; i >= 0; i--) {
        printf("%d\n", stack[i]);
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
