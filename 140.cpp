#include <bits/stdc++.h> 
/*************************************************************
 
    Following is the Binary Tree node structure

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
    };

*************************************************************/
//https://www.codingninjas.com/studio/problems/partial-bst_8230723?challengeSlug=striver-sde-challenge&leftPanelTab=1
bool valid(BinaryTreeNode<int> *root, int minVal, int maxVal) 
{
    if(!root)
        return true;

    if(root->data < minVal or root->data > maxVal)
        return false;
    
    return valid(root->left, minVal, root->data) and valid(root->right, root->data, maxVal);
}
bool validateBST(BinaryTreeNode<int> *root) 
{
    // Write your code here
       return valid(root, INT_MIN, INT_MAX);
}
