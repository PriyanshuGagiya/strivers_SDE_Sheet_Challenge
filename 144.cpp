#include <bits/stdc++.h> 
//#include <bits/stdc++.h> https://www.codingninjas.com/studio/problems/ceil-from-bst_8230754?challengeSlug=striver-sde-challenge
/************************************************************

    Following is the TreeNode class structure:

    class BinaryTreeNode {
    public:
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;
        
        BinaryTreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
        
        ~BinaryTreeNode() {
            if (left) {
              delete left;
            }
            if (right) {
              delete right;
            }
        }
    };

************************************************************/

int findCeil(BinaryTreeNode<int> *node, int x)
{
    // Write your code here.
    int ceil=-1;
    BinaryTreeNode<int>* trav=node;
    while(trav)
    {
        if(trav->data<x)
        {
            
            trav=trav->right;
        }
        else
        {
            ceil=trav->data;
            trav=trav->left;
        }
    }
    return ceil;
https://www.codingninjas.com/studio/problems/ceil-from-bst_8230754?challengeSlug=striver-sde-challenge/************************************************************

    Following is the TreeNode class structure:

    class BinaryTreeNode {
    public:
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;
        
        BinaryTreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
        
        ~BinaryTreeNode() {
            if (left) {
              delete left;
            }
            if (right) {
              delete right;
            }
        }
    };

************************************************************/

int findCeil(BinaryTreeNode<int> *node, int x)
{
    // Write your code here.
    int ceil=-1;
    BinaryTreeNode<int>* trav=node;
    while(trav)
    {
        if(trav->data<x)
        {
            
            trav=trav->right;
        }
        else
        {
            ceil=trav->data;
            trav=trav->left;
        }
    }
    return ceil;
}
