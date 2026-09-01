#ifndef TREENODE_HPP
#define TREENODE_HPP

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode() : val(0), right(nullptr), left(nullptr) {}
    TreeNode(int val) : val(val), right(nullptr), left(nullptr) {}
    TreeNode(int val, TreeNode* left, TreeNode* right) : val(val), right(right), left(left) {}
};

#endif