#include "TreeNode.h"
struct TreeNode{
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};
struct TreeNode* MakeTreeNode(int val){
    struct TreeNode* node=(struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val=val;
    node->left=NULL;
    node->right=NULL;
    return node;
}