#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "queue.h"

int main(){
    struct queue* myQueue=NewQueue();

    enqueue(myQueue, 2); enqueue(myQueue, 5);
    enqueue(myQueue, 10); enqueue(myQueue, 7);
    
    dequeue(myQueue);
    printf("the front element of the queue: %d\n", front(myQueue));
    printf("the size of the queue: %d\n", getQueueSize(myQueue));

    if (isQueueEmpty(myQueue)) printf("the queue is empty!\n");
    else printf("the queue is not empty!");

    return 0;
}