#include <bits/stdc++.h> 
//https://www.codingninjas.com/studio/problems/is-height-balanced-binary-tree_8230771?challengeSlug=striver-sde-challenge&leftPanelTab=1
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
int solve(BinaryTreeNode<int>* root) 
{
    if(!root) return 0;
    int lh=0,rh=0;
    if(root->left)
    {
        lh=solve(root->left);
    }
    if(root->right)
    {
        rh=solve(root->right);
    }
    if(lh==-1 || rh==-1)
    {
        return -1;
    }
    if(abs(lh-rh)>1)
    {
        return -1;
    }
    return 1+max(lh,rh);

}
bool isBalancedBT(BinaryTreeNode<int>* root) 
{
    return solve(root)!=-1;
}
