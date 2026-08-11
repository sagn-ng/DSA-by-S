#include "ListNode.h"
struct ListNode{
    int val;
    struct ListNode* next;
};
struct ListNode* MakeListNode(int val){
    struct ListNode* node=(struct ListNode*)malloc(sizeof(struct ListNode));
    node->val=val;
    node->next=NULL;
    return node;
}