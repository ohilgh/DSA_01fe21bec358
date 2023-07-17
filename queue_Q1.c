#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the queue
struct Node {
    int data;
    struct Node* next;
};

// Structure for the queue
struct Queue {
    struct Node* front;
    struct Node* rear;
};

// Function to initialize an empty queue
void initializeQueue(struct Queue* queue) {
    queue->front = queue->rear = NULL;
}

// Function to check if the queue is empty
int isQueueEmpty(struct Queue* queue) {
    return (queue->front == NULL);
}

// Function to add an element to the rear of the queue
void enqueue(struct Queue* queue, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (queue->rear == NULL) {
        queue->front = queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
    printf("Enqueued element %d at memory address %p\n", data, newNode);
}

// Function to remove an element from the front of the queue
int dequeue(struct Queue* queue) {
    if (isQueueEmpty(queue)) {
        printf("Queue is empty.\n");
        return -1;
    }

    struct Node* temp = queue->front;
    int data = temp->data;
    queue->front = queue->front->next;

    if (queue->front == NULL) {
        queue->rear = NULL;
    }

    printf("Dequeued element %d from memory address %p\n", data, temp);
    free(temp);
    return data;
}

// Function to copy one queue to another
void copyQueue(struct Queue* sourceQueue, struct Queue* destinationQueue) {
    struct Node* temp = sourceQueue->front;
    while (temp != NULL) {
        enqueue(destinationQueue, temp->data);
        temp = temp->next;
    }
}

// Function to display the elements of the queue
void displayQueue(struct Queue* queue) {
    if (isQueueEmpty(queue)) {
        printf("Queue is empty.\n");
        return;
    }

    struct Node* temp = queue->front;
    printf("Queue elements:\n");
    while (temp != NULL) {
        printf("%d at memory address %p\n", temp->data, temp);
        temp = temp->next;
    }
}

int main() {
    struct Queue sourceQueue, destinationQueue;
    initializeQueue(&sourceQueue);
    initializeQueue(&destinationQueue);

    int numElements, data;
    printf("Enter the number of elements in the source queue: ");
    scanf("%d", &numElements);

    printf("Enter the elements of the source queue:\n");
    for (int i = 0; i < numElements; i++) {
        scanf("%d", &data);
        enqueue(&sourceQueue, data);
    }

    copyQueue(&sourceQueue, &destinationQueue);

    printf("\nSource queue:\n");
    displayQueue(&sourceQueue);

    printf("\nDestination queue (copy of source queue):\n");
    displayQueue(&destinationQueue);

    return 0;
}
