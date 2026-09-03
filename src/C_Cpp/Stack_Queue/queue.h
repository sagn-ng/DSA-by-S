#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>

struct queue{
    int* queueArray;
    int queueCapacity;
    int queueSize;
    int first;
    int last;
};

struct queue* NewQueue();

void enqueue(struct queue* qu, int x);

void dequeue(struct queue* qu);

int front(struct queue* qu);

int getQueueSize(struct queue* qu);

bool isQueueEmpty(struct queue* qu);

#endif