#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name[20];
    int priority;
} Job;

typedef struct {
    Job *jobs;
    int size;
    int capacity;
} Queue;

Queue* createQueue(int capacity) {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->jobs = (Job*)malloc(capacity * sizeof(Job));
    queue->size = 0;
    queue->capacity = capacity;
    return queue;
}

void enqueue(Queue* queue, Job job) {
    if (queue->size >= queue->capacity) {
        printf("Queue is full. Cannot enqueue more jobs.\n");
        return;
    }
    queue->jobs[queue->size++] = job;
}

void printQueue(Queue* queue, int queueNumber) {
    printf("Q%d: ", queueNumber);
    for (int i = 0; i < queue->size; i++) {
        printf("%s, %d  ", queue->jobs[i].name, queue->jobs[i].priority);
    }
    printf("\n");
}

int main() {
    int numPriorities = 4;
    Queue** queues = (Queue*)malloc(numPriorities * sizeof(Queue));
    int i;

    for (i = 0; i < numPriorities; i++) {
        queues[i] = createQueue(10);
    }

    Job jobs[] = {
        {"ABC", 2},
        {"XYZ", 1},
        {"PQR", 1},
        {"RTZ", 3},
        {"CBZ", 2},
        {"QQQ", 3},
        {"XXX", 4},
        {"RRR", 1}
    };

    int numJobs = sizeof(jobs) / sizeof(jobs[0]);

    for (i = 0; i < numJobs; i++) {
        Job job = jobs[i];
        int priority = job.priority;
        if (priority >= 1 && priority <= numPriorities) {
            enqueue(queues[priority - 1], job);
        }
    }

    for (i = 0; i < numPriorities; i++) {
        printQueue(queues[i], i + 1);
    }

    for (i = 0; i < numPriorities; i++) {
        free(queues[i]->jobs);
        free(queues[i]);
    }
    free(queues);

    return 0;
}
