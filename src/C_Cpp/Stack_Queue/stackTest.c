#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int main(){
    struct stack* myStack=NewStack();

    push(myStack, 2); push(myStack, 5); push(myStack, 10); push(myStack, 7);
    pop(myStack);

    printf("%d\n", peek(myStack));
    printf("Current size of the stack: %d\n", getStackSize(myStack));

    return 0;
}