#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure.

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
//https://www.codingninjas.com/studio/problems/flatten-binary-tree-to-linked-list_8230817?challengeSlug=striver-sde-challenge&leftPanelTab=1
TreeNode<int> *flattenBinaryTree(TreeNode<int> *root)
{
    // Write your code here.
    TreeNode<int>*curr=root;
    while(curr)
    {
        if(curr->left)
        {
        TreeNode<int>*temp=curr->left;
        while (temp->right) {
          temp = temp->right;
        }
        temp->right = curr->right;
        curr->right = curr->left;
        curr->left = NULL;
        }
        curr=curr->right;
    }
    return root;
}
