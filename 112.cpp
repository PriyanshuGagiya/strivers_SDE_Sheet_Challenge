#include <bits/stdc++.h> 
/*
    Following is Binary Tree Node structure:
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };
*/
//https://www.codingninjas.com/codestudio/problems/inorder-traversal_8230857?challengeSlug=striver-sde-challenge&leftPanelTab=1
void preorder(TreeNode* root,vector<int>&ans)
{
    if(!root) return;
    ans.push_back(root->data);
    preorder(root->left,ans);
    preorder(root->right,ans);
}
vector<int> getPreOrderTraversal(TreeNode *root)
{
    // Write your code here.
    vector<int>ans;
    preorder(root,ans);
    return ans;
}
