#include <bits/stdc++.h> 
//https://www.codingninjas.com/studio/problems/construct-binary-tree-from-inorder-and-preorder-traversal_8230759?challengeSlug=striver-sde-challenge&leftPanelTab=1
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

TreeNode<int>* func(vector<int> &inorder, vector<int> &preorder, int is, int ie, int ps, int pe, unordered_map<int,int>& mp)
{
    if (ps > pe || is > ie) return NULL; 
    TreeNode<int>* root = new TreeNode<int>(preorder[ps]);
    int ind = mp[root->data];
    int sz = ind - is;
    root->left = func(inorder, preorder, is, ind - 1, ps + 1, ps + sz, mp);
    root->right = func(inorder, preorder, ind + 1, ie, ps + sz + 1, pe, mp);
    return root;
}

TreeNode<int>* buildBinaryTree(vector<int> &inorder, vector<int> &preorder)
{
    unordered_map<int, int> mp;
    int n = inorder.size();
    for (int i = 0; i < n; i++)
    {
        mp[inorder[i]] = i;
    }
    return func(inorder, preorder, 0, n - 1, 0, preorder.size() - 1, mp);
}

