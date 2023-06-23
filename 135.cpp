#include <bits/stdc++.h> 
//https://www.codingninjas.com/studio/problems/children-sum-property_8230711?challengeSlug=striver-sde-challenge&leftPanelTab=1
/*************************************************************

    Following is the Binary Tree node structure

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode < T > *left;
        BinaryTreeNode < T > *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/
void changeTree(BinaryTreeNode < int > * root) 
{
    // Write your code here.
    if(!root) return;
    int child=0;
    if(root->left)
    {
        child+=root->left->data;
    }
    if (root->right) {
      child += root->right->data;
    }
    if(child>=root->data)
    {
        root->data=child;
    }
    else
    {
        if(root->left)
        {
            root->left->data=root->data;
        }
        if (root->right) 
        {
            root->right->data= root->data;
        }
    }
    changeTree(root->left);
    changeTree(root->right);
    if(!root->left and !root->right)
    {
        return;
    }
    root->data=0;
    if(root->left)
    root->data+=root->left->data;
    if(root->right)
    {
        root->data+=root->right->data;
    }
}
