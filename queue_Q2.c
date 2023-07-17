#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Deque {
    struct Node* front;
    struct Node* rear;
};

void initializeDeque(struct Deque* deque) {
    deque->front = deque->rear = NULL;
}

int isDequeEmpty(struct Deque* deque) {
    return (deque->front == NULL);
}

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = newNode->next = NULL;
    return newNode;
}

void addFront(struct Deque* deque, int data) {
    struct Node* newNode = createNode(data);

    if (isDequeEmpty(deque)) {
        deque->front = deque->rear = newNode;
    } else {
        newNode->next = deque->front;
        deque->front->prev = newNode;
        deque->front = newNode;
    }

    printf("Added %d at the front of the deque (Address: %p).\n", data, newNode);
}

void addRear(struct Deque* deque, int data) {
    struct Node* newNode = createNode(data);

    if (isDequeEmpty(deque)) {
        deque->front = deque->rear = newNode;
    } else {
        newNode->prev = deque->rear;
        deque->rear->next = newNode;
        deque->rear = newNode;
    }

    printf("Added %d at the rear of the deque (Address: %p).\n", data, newNode);
}

int deleteFront(struct Deque* deque) {
    if (isDequeEmpty(deque)) {
        printf("Deque is empty.\n");
        return -1;
    }

    struct Node* temp = deque->front;
    int data = temp->data;

    deque->front = deque->front->next;

    if (deque->front == NULL) {
        deque->rear = NULL;
    } else {
        deque->front->prev = NULL;
    }

    free(temp);
    printf("Deleted %d from the front of the deque.\n", data);
    return data;
}

int deleteRear(struct Deque* deque) {
    if (isDequeEmpty(deque)) {
        printf("Deque is empty.\n");
        return -1;
    }

    struct Node* temp = deque->rear;
    int data = temp->data;

    deque->rear = deque->rear->prev;

    if (deque->rear == NULL) {
        deque->front = NULL;
    } else {
        deque->rear->next = NULL;
    }

    free(temp);
    printf("Deleted %d from the rear of the deque.\n", data);
    return data;
}

void displayDeque(struct Deque* deque) {
    if (isDequeEmpty(deque)) {
        printf("Deque is empty.\n");
        return;
    }

    struct Node* temp = deque->front;
    printf("Deque elements (front to rear):\n");
    while (temp != NULL) {
        printf("%d (Address: %p)\n", temp->data, temp);
        temp = temp->next;
    }
}

int main() {
    struct Deque deque;
    initializeDeque(&deque);

    int choice, data;

    while (1) {
        printf("---- Deque Operations ----\n");
        printf("1. Add element at front\n");
        printf("2. Add element at rear\n");
        printf("3. Delete element from front\n");
        printf("4. Delete element from rear\n");
        printf("5. Display deque\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to add at the front: ");
                scanf("%d", &data);
                addFront(&deque, data);
                break;
            case 2:
                printf("Enter the element to add at the rear: ");
                scanf("%d", &data);
                addRear(&deque, data);
                break;
            case 3:
                deleteFront(&deque);
                break;
            case 4:
                deleteRear(&deque);
                break;
            case 5:
                displayDeque(&deque);
                break;
            case 6:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }

        printf("\n");
    }

    return 0;
}
