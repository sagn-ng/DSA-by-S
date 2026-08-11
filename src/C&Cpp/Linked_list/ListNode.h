#ifndef LISTNODE
#define LISTNODE

#include <stdio.h>
#include <stdlib.h>
struct ListNode{
    int val;
    struct ListNode* next;
};
struct ListNode* MakeListNode(int val);

#endif