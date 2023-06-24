//https://www.codingninjas.com/studio/problems/invert-a-binary-tree_8230838?challengeSlug=striver-sde-challenge&leftPanelTab=1
#include <bits/stdc++.h> 
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
bool path(TreeNode<int>*root,TreeNode<int> *leaf,stack<TreeNode<int> *>&st)
{
    if(!root) return 0;
    if(!root->left and !root->right and root->data==leaf->data)
    {
        st.push(root);
        return 1;
    }
    st.push(root);
    if(path(root->left,leaf,st))
    {
        return 1;
    }
    if(path(root->right,leaf,st))
    {
        return 1;
    }
    st.pop();
    return 0;
}
TreeNode<int> * invertBinaryTree(TreeNode<int> *root, TreeNode<int> *leaf)
{
	// Write your code here.
    if(!root) return NULL;
    stack<TreeNode<int> *>st;
    path(root,leaf,st);

    TreeNode<int> *newroot=st.top();
    st.pop();
    TreeNode<int>*parent=newroot;
    while(!st.empty())
    {
        TreeNode<int> *curr=st.top();
        st.pop();
        if(curr->left==parent)
        {
            curr->left=NULL;
            parent->left=curr;
        }
        else
        {
            curr->right=curr->left;
            curr->left=NULL;
            parent->left=curr;
        }
        parent=parent->left;
    }
    return newroot;
}
