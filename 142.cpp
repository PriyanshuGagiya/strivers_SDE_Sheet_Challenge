//https://www.codingninjas.com/studio/problems/predecessor-and-successor-in-bst_8230742?challengeSlug=striver-sde-challenge&leftPanelTab=1
#include <bits/stdc++.h> 
/*************************************************************

    Following is the Binary Tree node structure

    travlate <typename T>

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~BinaryTreeNode() {
            if (left)
            {
                delete left;
            }
            if (right)
            {
                delete right;
            }
        }
    };

*************************************************************/

pair<int,int> predecessorSuccessor(BinaryTreeNode<int>* root, int key)
{
    // Write your code here.
    pair<int,int>ans={-1,-1};
    BinaryTreeNode<int>* trav = root;
    while(trav->data != key)
    {

        if(trav->data > key)
        {
            ans.second=trav->data;
            trav = trav->left;
        }
        else
        {
            ans.first=trav->data;
            trav = trav->right;
        }
    }
    BinaryTreeNode<int>* leftTree = trav->left;
    while(leftTree != NULL){
       ans.first= leftTree->data;
        leftTree = leftTree->right; 
    }
   
    BinaryTreeNode<int>* rightTree = trav->right;
    while (rightTree != NULL) {
      ans.second = rightTree->data;
      rightTree = rightTree->left; 
    }   
    return ans;
}
