#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* head = NULL;

void insertAtStart();
void insertAtEnd();
void insertAfterPosition();
void deleteFromStart();
void deleteFromPosition();
void printList();
int getLength();
void reverseList();

int main() {
    int choice;

    while (1) {
        printf("\n--- Linked List Menu ---\n");
        printf("1. Insert at start\n");
        printf("2. Insert at end\n");
        printf("3. Insert after position\n");
        printf("4. Delete from start\n");
        printf("5. Delete from position\n");
        printf("6. Print list\n");
        printf("7. Get length\n");
        printf("8. Reverse list\n");
        printf("9. Exit\n");
        printf("Choose: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: insertAtStart(); break;
            case 2: insertAtEnd(); break;
            case 3: insertAfterPosition(); break;
            case 4: deleteFromStart(); break;
            case 5: deleteFromPosition(); break;
            case 6: printList(); break;
            case 7: printf("List length: %d\n", getLength()); break;
            case 8: reverseList(); break;
            case 9: exit(0);
            default: printf("Invalid choice!\n");
        }
    }

    return 0;
}

void insertAtStart() {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) return;

    printf("Enter value: ");
    scanf("%d", &newNode->data);
    newNode->next = head;
    head = newNode;
}

void insertAtEnd() {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) return;

    printf("Enter value: ");
    scanf("%d", &newNode->data);
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
}

void insertAfterPosition() {
    int pos, count = 1;
    printf("Insert after position: ");
    scanf("%d", &pos);

    if (pos > getLength()) {
        printf("Position out of range!\n");
        return;
    }

    Node* temp = head;
    while (count < pos) {
        temp = temp->next;
        count++;
    }

    Node* newNode = (Node*)malloc(sizeof(Node));
    printf("Enter value: ");
    scanf("%d", &newNode->data);

    newNode->next = temp->next;
    temp->next = newNode;
}

void deleteFromStart() {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    Node* temp = head;
    head = head->next;
    free(temp);
}

void deleteFromPosition() {
    int pos, count = 1;
    printf("Delete node at position: ");
    scanf("%d", &pos);

    if (pos == 1) {
        deleteFromStart();
        return;
    }

    if (pos > getLength()) {
        printf("Invalid position!\n");
        return;
    }

    Node* temp = head;
    while (count < pos - 1) {
        temp = temp->next;
        count++;
    }

    Node* toDelete = temp->next;
    temp->next = toDelete->next;
    free(toDelete);
}

void printList() {
    Node* temp = head;
    printf("List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int getLength() {
    int count = 0;
    Node* temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

void reverseList() {
    Node* prev = NULL;
    Node* current = head;
    Node* next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
    printf("List reversed!\n");
}
