#include <bits/stdc++.h> 
//https://www.codingninjas.com/studio/problems/lca-of-binary-tree_8230760?challengeSlug=striver-sde-challenge&leftPanelTab=1
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
int solve(TreeNode<int> *root, int x, int y,int &ans)
{
    if(!root) return 0;
    if(root->data==x || root->data==y)
    {
        ans=root->data;
        return 1;
    }
    int left=solve(root->left,x,y,ans);
    int right=solve(root->right,x,y,ans);
    if(left and right)
    {
        ans=root->data;
    }
    if(left || right)
    {
        return 1;
    }
    return 0;
}
int lowestCommonAncestor(TreeNode<int> *root, int x, int y)
{
	//    Write your code her
    int ans=-1;
    solve(root,x,y,ans);
    return ans;
}
