#ifndef STACK_H
#define STACK_H

#include <stdbool.h>

struct stack{
    int* stackArray;
    int stackCapacity;
    int stackSize;
    int last;
};

struct stack* NewStack();

void push(struct stack* st, int x);

void pop(struct stack* st);

int peek(struct stack* st);

int getSize(struct stack* st);

bool isEmpty(struct stack* st);

#endif