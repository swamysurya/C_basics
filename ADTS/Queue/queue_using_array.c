#include <stdio.h>

#define MAX 5   // Maximum size of queue

int queue[MAX];  // Array to store queue elements
int front = -1;
int rear = -1;

// Function to check if queue is empty
int isEmpty() {
    if (front == -1 || front > rear)
        return 1;
    else
        return 0;
}

// Function to check if queue is full
int isFull() {
    if (rear == MAX - 1)
        return 1;
    else
        return 0;
}

// Enqueue operation (Insert element)
void enqueue(int value) {

    if (isFull()) {
        printf("Queue Overflow! Cannot insert %d\n", value);
        return;
    }

    if (front == -1)
        front = 0;   // First element insertion

    rear++;
    queue[rear] = value;

    printf("%d inserted into queue\n", value);
}

// Dequeue operation (Remove element)
int dequeue() {

    if (isEmpty()) {
        printf("Queue Underflow! Queue is empty\n");
        return -1;
    }

    int value = queue[front];
    front++;

    return value;
}

// Display queue elements
void display() {

    if (isEmpty()) {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue elements are:\n");

    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
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
