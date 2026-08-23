#include <stdio.h>
#include "ListNode.c"
int main(){
    struct ListNode* tail=MakeListNode(2);
    struct ListNode* head=MakeListNode(1);
    head->next=tail;
    printf("%d -> %d\n", head->val, tail->val);
    return 0;
}