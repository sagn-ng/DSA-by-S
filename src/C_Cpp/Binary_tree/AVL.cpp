#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

struct avlNode{
    int val;
    int height;
    avlNode* left;
    avlNode* right;

    avlNode(int val) : val(val), height(1), left(NULL), right(NULL) {}
};

class avlTree{
private:
    int getBalanceFactor(avlNode* X){
        if (X==NULL) return 0;
        return getHeight(X->left) - getHeight(X->right);
    }

    avlNode* rightRotate(avlNode* X){
        avlNode* Y=X->left;
        
        X->left=Y->right;
        //Y is the left child of the initial node X
        Y->right=X;

        X->height = 1 + max(getHeight(X->left), getHeight(X->right)); //update X's height
        Y->height = 1 + max(getHeight(Y->left), getHeight(Y->right)); //update Y's height

        return Y; //return the new root, which is Y
    }

    avlNode* leftRotate(avlNode* X){
        avlNode* Y=X->right;

        X->right=Y->left;
        //Y is the right child of the initial node X
        Y->left=X;

        X->height = 1 + max(getHeight(X->left), getHeight(X->right)); //update X's height
        Y->height = 1 + max(getHeight(Y->left), getHeight(Y->right)); //update Y's height

        return Y;
    } //symmetric to rightRotate

    avlNode* Rotate(avlNode* node){
        int bf=getBalanceFactor(node);
        if (bf>1){
            /*L case: simply do a right rotation on node
            L-R case: must do a left rotation on node's left
            child first*/
            if (getBalanceFactor(node->left)==-1){
                node->left = leftRotate(node->left);
            }

            return rightRotate(node);
        }   //L case or L-R case

        else if (bf<-1){
            /*R case: simply do a left rotation on node
            R-L case: must do a right rotation on node's right
            child first*/
            if (getBalanceFactor(node->right)==1){
                node->right=rightRotate(node->right);
            }

            return leftRotate(node);
        }   //R case or R-L case
    
        //if node remains unchanged (i.e balanced), return it:
        return node;
    }

    avlNode* minNodeBST(avlNode* node){
        avlNode* cur=node;
        while (cur->left!=NULL) cur=cur->left;
        return cur;
    }   //find the smallest element in a BST

public:
    int getHeight(avlNode* X){
        if (X==NULL) return 0;
        return X->height;
    }

    //insert key k into the subtree rooted at node
    avlNode* insert(avlNode* node, int k){
        if (node==NULL) return new avlNode(k);  //if we found an empty place

        if (k < node->val){
            node->left=insert(node->left, k);
        }   //go down left

        else if (k > node->val){
            node->right=insert(node->right, k);
        }   //go down right

        else return node;   //duplicates aren't allowed in BST

        //update the height
        node->height = 1 + max(getHeight(node->left), getHeight(node->right));

        return Rotate(node);    //perform rotations if needed:
    }

    avlNode* deleteNode(avlNode* node, int k){
        //1: perform a normal BST deletion
        if (node==NULL) return node;
        
        if (k < node->val) node->left=deleteNode(node->left, k);

        else if (k > node->val) node->right=deleteNode(node->right, k);

        else{   //found the node to be deleted
            if (node->left==NULL  && node->right==NULL){
                node=NULL;
                return NULL;
            } //no child case

            else if (node->left!=NULL && node->right!=NULL){
                //the "min" node of the right subtree becomes the new root:
                avlNode* temp=minNodeBST(node->right);
                node->val=temp->val;

                node->right=deleteNode(node->right, node->val);
            } //2 children case

            else{
                avlNode* temp=(node->left) ? node->left : node->right;
                node=temp;
                temp=NULL;
                return node;
            } //only 1 child case
        }

        //2: perform rotations if needed
        return Rotate(node);
    }

    void preOrder(avlNode* root){
        if (root != NULL) { 
            cout << root->val << " "; 
            preOrder(root->left);
            preOrder(root->right); 
        } 
    } //preorder traversal
};

int main(){
    avlNode* root=NULL;
    avlTree myTree;
    root=myTree.insert(root,10); root=myTree.insert(root,15); root=myTree.insert(root,20);
    root=myTree.insert(root,30); root=myTree.insert(root, 5); root=myTree.insert(root,45);
    root=myTree.insert(root, 2); root=myTree.insert(root,25);
    root=myTree.deleteNode(root,5);
    myTree.preOrder(root);
    return 0;
}