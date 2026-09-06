#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

struct avlNode{
    int val;
    int height;
    avlNode* left;
    avlNode* right;

    avlNode(int val) : val(val), height(1), left(nullptr), right(nullptr) {}
};

class avlTree{
    avlNode* root;

    int getHeight(avlNode* X){
        if (X==nullptr) return 0;
        return X->height;
    }

    int getBalanceFactor(avlNode* X){
        return X->left->height - X->right->height;
    }

    avlNode* rightRotate(avlNode* X){
        avlNode* Y=X->left;
        
        X->left=Y->right;
        X->height = 1 + max(X->left->height, X->right->height); //update X's height

        //Y is the left child of the initial node X
        Y->right=X;
        Y->height = 1 + max(Y->left->height, Y->right->height); //update Y's height

        return Y; //return the new root, which is Y
    }

    avlNode* leftRotate(avlNode* X){
        avlNode* Y=X->right;

        X->right=Y->left;
        X->height = 1 + max(X->left->height, X->right->height); //update X's height

        //Y is the right child of the initial node X
        Y->left=X;
        Y->height = 1 + max(Y->left->height, Y->right->height); //update Y's height

        return Y;
    } //symmetric to rightRotate

    //insert key k into the subtree rooted at node
    avlNode* insert(avlNode* node, int k){
        if (node==nullptr) return new avlNode(k); //if we found an empty place

        if (k < node->val){
            node->left=insert(node->left, k);
        } //go down left

        else if (k > node->val) insert(node->right, k); //go down right

        else return node; //duplicates aren't allowed in BST

        //update the height
        node->height = 1 + max(node->left->height, node->right->height);

        //perform rotations if needed:
        int bf=getBalanceFactor(node);
        if (bf>1){
            /*L case: simply do a right rotation on node
            L-R case: must do a left rotation on node's left
            child first*/
            if (getBalanceFactor(node->left)==-1){
                node->left = leftRotate(node->left);
            }

            return rightRotate(node);
        } //L case or L-R case

        else if (bf<-1){
            /*R case: simply do a left rotation on node
            R-L case: must do a right rotation on node's right
            child first*/
            if (getBalanceFactor(node->right)==1){
                node->right=rightRotate(node->right);
            }

            return leftRotate(node);
        } //R case or R-L case
    
        //if node remains unchanged (i.e balanced), return it:
        return node;
    }

    
};