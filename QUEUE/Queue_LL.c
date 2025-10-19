#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Front and rear pointers
struct Node* front = NULL;
struct Node* rear = NULL;

// Enqueue function - insert at rear
void enqueue(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed\n");
        return;
    }
    newNode->data = value;
    newNode->next = NULL;

    if (front == NULL && rear == NULL) { // Empty queue
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
    printf("%d enqueued to the queue\n", value);
}

// Dequeue function - remove from front
void dequeue() {
    if (front == NULL) {
        printf("Queue is empty! Cannot dequeue.\n");
        return;
    }
    struct Node* temp = front;
    printf("%d dequeued from the queue\n", front->data);
    front = front->next;

    if (front == NULL) { // Queue becomes empty
        rear = NULL;
    }
    free(temp);
}

// Display function
void display() {
    if (front == NULL) {
        printf("Queue is empty\n");
        return;
    }
    struct Node* temp = front;
    printf("Queue elements: ");
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

    dequeue();
    display();

    dequeue();
    dequeue();
    dequeue();  // Extra dequeue to test empty queue condition

    return 0;
}
