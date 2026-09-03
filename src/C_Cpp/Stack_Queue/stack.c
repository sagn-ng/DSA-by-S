#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "stack.h"

struct stack* NewStack(){
    struct stack* st=(struct stack*)malloc(sizeof(struct stack));

    st->stackCapacity=1e4;
    st->stackArray=(int*)malloc(sizeof(int)*(st->stackCapacity));
    st->last=-1;
    st->stackSize=0;

    return st;
}

void push(struct stack* st, int x){
    if (st->stackSize==st->stackCapacity){
        printf("The stack is full! Cannot add anymore!\n");
        return;
    }

    (st->stackArray)[++st->last]=x;
    st->stackSize++;
}

void pop(struct stack* st){
    if (st->stackSize==0){
        printf("The stack is empty! There's nothing to remove!\n");
        return;
    }

    (st->last)--;
    (st->stackSize)--;
}

int peek(struct stack* st){
    if (st->stackSize==0){
        printf("The stack is empty! There's nothing to remove!\n");
        return -1000000;
    }

    return (st->stackArray)[st->last];

}

int getStackSize(struct stack* st){
    return st->stackSize;
}

bool isStackEmpty(struct stack* st){
    return (st->stackSize==0);
}