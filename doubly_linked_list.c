#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

void appendAtBeginning(struct Node** head, int newData) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = newData;
    newNode->prev = NULL;
    newNode->next = *head;

    if (*head != NULL) {
        (*head)->prev = newNode;
    }

    *head = newNode;
}

void appendAtEnd(struct Node** head, int newData) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = newData;
    newNode->next = NULL;

    if (*head == NULL) {
        newNode->prev = NULL;
        *head = newNode;
        return;
    }

    struct Node* last = *head;
    while (last->next != NULL) {
        last = last->next;
    }

    last->next = newNode;
    newNode->prev = last;
}

void displayLinkedList(struct Node* head) {
    printf("Linked List: ");
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

void addAfterNode(struct Node* head, int position, int newData) {
    struct Node* currentNode = head;

    while (position > 1) {
        currentNode = currentNode->next;
        if (currentNode == NULL) {
            printf("Error: Specified position is beyond the length of the linked list.\n");
            return;
        }
        position--;
    }

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = newData;
    newNode->next = currentNode->next;
    newNode->prev = currentNode;

    if (currentNode->next != NULL) {
        currentNode->next->prev = newNode;
    }

    currentNode->next = newNode;
}

void deleteAtEnd(struct Node** head) {
    if (*head == NULL) {
        printf("Error: Linked list is empty.\n");
        return;
    }

    struct Node* last = *head;
    while (last->next != NULL) {
        last = last->next;
    }

    if (last->prev != NULL) {
        last->prev->next = NULL;
    } else {
        *head = NULL;
    }

    free(last);
}

void deleteAtBeginning(struct Node** head) {
    if (*head == NULL) {
        printf("Error: Linked list is empty.\n");
        return;
    }

    struct Node* temp = *head;
    *head = (*head)->next;

    if (*head != NULL) {
        (*head)->prev = NULL;
    }

    free(temp);
}

void deleteByValue(struct Node** head, int value) {
    if (*head == NULL) {
        printf("Error: Linked list is empty.\n");
        return;
    }

    struct Node* currentNode = *head;

    while (currentNode != NULL && currentNode->data != value) {
        currentNode = currentNode->next;
    }

    if (currentNode == NULL) {
        printf("Error: Value not found in the linked list.\n");
        return;
    }

    if (currentNode->prev != NULL) {
        currentNode->prev->next = currentNode->next;
    } else {
        *head = currentNode->next;
    }

    if (currentNode->next != NULL) {
        currentNode->next->prev = currentNode->prev;
    }

    free(currentNode);
}

int main() {
    struct Node* head = NULL;

    int choice, data, position, value;

    do {
        printf("\n");
        printf("........Doubly Linked List Operations.......\n");
        printf("\n");
        printf("1. Append at the beginning\n");
        printf("2. Add at the end\n");
        printf("3. Display the linked list\n");
        printf("4. Add after a specified node\n");
        printf("5. Delete at the end\n");
        printf("6. Delete at the beginning\n");
        printf("7. Delete a specified node\n");
        printf("8. Exit\n");
        printf("\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the data: ");
                scanf("%d", &data);
                appendAtBeginning(&head, data);
                break;
            case 2:
                printf("Enter the data: ");
                scanf("%d", &data);
                appendAtEnd(&head, data);
                break;
            case 3:
                displayLinkedList(head);
                break;
            case 4:
                printf("Enter the position: ");
                scanf("%d", &position);
                printf("Enter the data: ");
                scanf("%d", &data);
                addAfterNode(head, position, data);
                break;
            case 5:
                deleteAtEnd(&head);
                break;
            case 6:
                deleteAtBeginning(&head);
                break;
            case 7:
                printf("Enter the value to delete: ");
                scanf("%d", &value);
                deleteByValue(&head, value);
                break;
            case 8:
                while (head != NULL) {
                    struct Node* temp = head;
                    head = head->next;
                    free(temp);
                }
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 8);

    return 0;
}

