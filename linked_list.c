#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void appendAtBeginning(struct Node** head, int newData) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = newData;
    newNode->next = *head;
    *head = newNode;
}

void appendAtEnd(struct Node** head, int newData) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = newData;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node* last = *head;
    while (last->next != NULL) {
        last = last->next;
    }

    last->next = newNode;
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
    currentNode->next = newNode;
}

void deleteAtEnd(struct Node** head) {
    if (*head == NULL) {
        printf("Error: Linked list is empty.\n");
        return;
    }

    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }

    struct Node* secondLast = *head;
    while (secondLast->next->next != NULL) {
        secondLast = secondLast->next;
    }

    free(secondLast->next);
    secondLast->next = NULL;
}

void deleteAtBeginning(struct Node** head) {
    if (*head == NULL) {
        printf("Error: Linked list is empty.\n");
        return;
    }

    struct Node* temp = *head;
    *head = (*head)->next;

    free(temp);
}

void deleteByValue(struct Node** head, int value) {
    if (*head == NULL) {
        printf("Error: Linked list is empty.\n");
        return;
    }

    struct Node* currentNode = *head;
    struct Node* prevNode = NULL;

    if (currentNode != NULL && currentNode->data == value) {
        *head = currentNode->next;
        free(currentNode);
        return;
    }

    while (currentNode != NULL && currentNode->data != value) {
        prevNode = currentNode;
        currentNode = currentNode->next;
    }

    if (currentNode == NULL) {
        printf("Error: Value not found in the linked list.\n");
        return;
    }

    prevNode->next = currentNode->next;
    free(currentNode);
}

int main() {
    struct Node* head = NULL;

    int choice, data, position, value;
    struct Node* current = NULL;
    struct Node* next = NULL;

    do {
        printf("\n");
        printf("........Linked List Operations.......\n");
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
                current = head;
                while (current != NULL) {
                    next = current->next;
                    free(current);
                    current = next;
                }
                head = NULL;
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 8);

    return 0;
}
