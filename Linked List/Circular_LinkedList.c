#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

// Create a circular linked list with n nodes
void create(int n) {
    if (n <= 0) return;
    struct Node *temp, *last;
    head = (struct Node*)malloc(sizeof(struct Node));
    printf("Enter data for node 1: ");
    scanf("%d", &head->data);
    head->next = head;
    last = head;

    for (int i = 2; i <= n; i++) {
        temp = (struct Node*)malloc(sizeof(struct Node));
        printf("Enter data for node %d: ", i);
        scanf("%d", &temp->data);
        temp->next = head;
        last->next = temp;
        last = temp;
    }
}

// Display the circular linked list
void display() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(head)\n");
}

// Insert at any position
void insertAtPos(int pos, int value) {
    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = value;

    if (pos == 1) { // Insert at beginning
        if (head == NULL) {
            head = temp;
            head->next = head;
        } else {
            struct Node* last = head;
            while (last->next != head)
                last = last->next;
            temp->next = head;
            last->next = temp;
            head = temp;
        }
        return;
    }

    struct Node *current = head;
    for (int i = 1; i < pos - 1; i++) {
        current = current->next;
        if (current == head) {
            printf("Position out of range.\n");
            free(temp);
            return;
        }
    }
    temp->next = current->next;
    current->next = temp;
}

// Delete at any position
void deleteAtPos(int pos) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node *temp = head, *prev;
    if (pos == 1) { // Delete head
        if (head->next == head) {
            free(head);
            head = NULL;
            return;
        }
        prev = head;
        while (prev->next != head)
            prev = prev->next;
        struct Node* toDelete = head;
        head = head->next;
        prev->next = head;
        free(toDelete);
        return;
    }

    for (int i = 1; i < pos; i++) {
        prev = temp;
        temp = temp->next;
        if (temp == head) {
            printf("Position out of range.\n");
            return;
        }
    }
    prev->next = temp->next;
    free(temp);
}

int main() {
    int n;
    printf("ABHINEET KUMAR\n");
    printf("Enter number of nodes to create: ");
    scanf("%d", &n);
    create(n);

    printf("\nOriginal list:\n");
    display();

    printf("\nInsert 99 at position 2:\n");
    insertAtPos(2, 99);
    display();

    printf("\nInsert 77 at position 1:\n");
    insertAtPos(1, 77);
    display();

    printf("\nDelete node at position 3:\n");
    deleteAtPos(3);
    display();

    printf("\nDelete node at position 1:\n");
    deleteAtPos(1);
    display();

    return 0;
}
