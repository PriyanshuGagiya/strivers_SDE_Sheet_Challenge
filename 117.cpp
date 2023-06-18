#include <bits/stdc++.h> 
/************************************************************

    Following is the Binary Tree node structure:

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


************************************************************/
//https://www.codingninjas.com/codestudio/problems/tree-traversals_8230775?challengeSlug=striver-sde-challenge&leftPanelTab=1
void solve(BinaryTreeNode<int>*root,vector<int>&preorder,vector<int>&inorder,vector<int>&postorder)
{
    if(!root) return;
    preorder.push_back(root->data);
    solve(root->left,preorder,inorder,postorder);
    inorder.push_back(root->data);
    solve(root->right,preorder,inorder,postorder);
    postorder.push_back(root->data);
}
vector<vector<int>> getTreeTraversal(BinaryTreeNode<int> *root)
{
   vector<int>preorder,inorder,postorder;
   solve(root,preorder,inorder,postorder);
   vector<vector<int>>ans;
   ans.push_back(inorder);
   ans.push_back(preorder);
   ans.push_back(postorder);
   return ans;
}
