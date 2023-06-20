#include <bits/stdc++.h> 
/*
    Following is the Binary Tree node structure:

    class BinaryTreeNode {
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
*/
//https://www.codingninjas.com/studio/problems/search-in-bst_8230841?challengeSlug=striver-sde-challenge&leftPanelTab=1
bool searchInBST(BinaryTreeNode<int> *root, int x) 
{
    // Write your code here.
    while(root)
    {
        if(root->data==x)
        {
            return 1;
        }
        if(root->data<x)
        {
            root=root->right;
        }
        else
        {
            root=root->left;
        }
    }
    return 0;
}
