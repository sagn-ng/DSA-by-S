#include <stdio.h>
#include <stdlib.h>
#include "TreeNode.h"

struct TreeNode* MakeTreeNode(int val, struct TreeNode* left, struct TreeNode* right){
    struct TreeNode* node=(struct TreeNode*)malloc(sizeof(struct TreeNode));

    node->val=val;
    node->left=left;
    node->right=right;

    return node;
}

int main(){
    struct TreeNode* left=MakeTreeNode(5, NULL, NULL);

    struct TreeNode* right=MakeTreeNode(10, NULL, NULL);

    struct TreeNode* root=MakeTreeNode(2, left, right);

    printf("%d %d %d", root->val, root->left->val, root->right->val);
    return 0;
}