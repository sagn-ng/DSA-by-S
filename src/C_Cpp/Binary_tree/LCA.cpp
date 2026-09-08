#include <iostream>
#include <vector>
#include "TreeNode.hpp"
using namespace std;

void find(TreeNode*root, TreeNode* target, vector<TreeNode*> &path){
    //"target" is guaranteed to exist in the BST
    path.push_back(root);
    if (target->val > root->val){
        find(root->right, target, path);
    }
    else if (target->val < root->val){
        find(root->left, target, path);
    }
    else return;
}   //perform a normal search in a BST
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    vector<TreeNode*> pathP;
    vector<TreeNode*> pathQ;

    find(root, p, pathP);
    find(root, q, pathQ);

    int num1=pathP.size(), num2=pathQ.size();
    int i=0, j=0;
    TreeNode* res;
    while (i<num1 && j<num2 && pathP[i]==pathQ[j]){
        res=pathP[i];
        i++;
        j++;
    }   //loop until we see the first different node

    return res;
}