#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void createList(int n) {
    int value;
    struct Node *temp, *newNode;

    for (int i = 0; i < n; i++) {
        printf("Enter value for node %d: ", i + 1);
        scanf("%d", &value);
        newNode = createNode(value);
        if (head == NULL)
            head = temp = newNode;
        else {
            temp->next = newNode;
            temp = newNode;
        }
    }
}

void displayList() {
    struct Node* temp = head;
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void insertAtPosition(int pos, int value) {
    struct Node* newNode = createNode(value);
    if (pos == 1) {
        newNode->next = head;
        head = newNode;
        return;
    }

    struct Node* temp = head;
    for (int i = 1; temp != NULL && i < pos - 1; i++)
        temp = temp->next;

    if (temp == NULL)
        printf("Invalid position!\n");
    else {
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

void deleteAtPosition(int pos) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    struct Node *temp = head, *prev;

    if (pos == 1) {
        head = head->next;
        free(temp);
        return;
    }

    for (int i = 1; temp != NULL && i < pos; i++) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Invalid position!\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
}

int main() {
    int n, pos, value;
    printf("ABHINEET KUMAR\n");
    printf("Enter number of nodes to create: ");
    scanf("%d", &n);
    createList(n);

    printf("\nOriginal List:\n");
    displayList();

    printf("\nEnter position to insert: ");
    scanf("%d", &pos);
    printf("Enter value to insert: ");
    scanf("%d", &value);
    insertAtPosition(pos, value);

    printf("\nList after insertion:\n");
    displayList();

    printf("\nEnter position to delete: ");
    scanf("%d", &pos);
    deleteAtPosition(pos);

    printf("\nList after deletion:\n");
    displayList();

    return 0;
}
