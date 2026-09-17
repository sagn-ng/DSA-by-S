#ifndef TREENODE_H
#define TREENODE_H

struct TreeNode
{
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct TreeNode* MakeTreeNode(int val, struct TreeNode* left, struct TreeNode* right){
    struct TreeNode* node=(struct TreeNode*)malloc(sizeof(struct TreeNode));

    node->val=val;
    node->left=left;
    node->right=right;

    return node;
}
#endif