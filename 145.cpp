#include <bits/stdc++.h> 
//https://www.codingninjas.com/studio/problems/k-th-largest-number-bst_8230750?challengeSlug=striver-sde-challenge&leftPanelTab=1
/************************************************************
    Following is the Binary Search Tree node structure
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/
void solve(TreeNode<int>*root,vector<int>&inorder)
{
    if(!root) return ;
    solve(root->left,inorder);
    inorder.push_back(root->data);
    solve(root->right,inorder);
}
int KthLargestNumber(TreeNode<int>* root, int k) 
{
    vector<int>inorder;
    solve(root,inorder);
    int n=inorder.size();
    if(n<k)
    {
        return -1;
    }
    return inorder[n-k];
    
}
