#include <stdio.h>
#include <stdlib.h>
#include "ListNode.h"

struct ListNode* MakeListNode(int val, struct ListNode* next){
    struct ListNode* node=(struct ListNode*)malloc(sizeof(struct ListNode));
    node->val=val;
    node->next=next;
    return node;
}

int main(){
    struct ListNode* tail=MakeListNode(2, NULL);
    struct ListNode* head=MakeListNode(1, NULL);
    head->next=tail;
    printf("%d -> %d\n", head->val, tail->val);
    return 0;
}