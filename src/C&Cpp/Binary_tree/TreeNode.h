#ifndef TREENODE
#define TREENODE
#include <stdio.h>
#include <stdlib.h>
struct TreeNode{
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};
struct TreeNode* MakeTreeNode(int val);

#endif