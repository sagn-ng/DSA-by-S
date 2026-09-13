#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "queue.h"

struct queue* NewQueue(){
    struct queue* qu=(struct queue*)malloc(sizeof(struct queue));

    qu->queueCapacity=1e4;
    qu->queueArray=(int*)malloc(sizeof(int)*(qu->queueCapacity));

    qu->first=0; qu->last=-1;
    qu->queueSize=0;

    return qu;
}

void enqueue(struct queue* qu, int x){
    if (qu->queueSize==qu->queueCapacity){
        printf("The queue is full! Cannot add anymore!\n");
        return;
    }

    qu->queueArray[++(qu->last)]=x;
    qu->queueSize++;
}

void dequeue(struct queue* qu){
    if (qu->queueSize==0){
        printf("The queue is empty! Nothing to remove!\n");
        return;
    }

    qu->first++;
    qu->queueSize--;
}

int front(struct queue* qu){
    if (qu->queueSize==0){
        printf("The queue is empty! Nothing to show!\n");
        return -1000000;
    }

    return qu->queueArray[qu->first];
}

int getQueueSize(struct queue* qu){
    return qu->queueSize;
}

bool isQueueEmpty(struct queue* qu){
    return (qu->queueSize==0);
}