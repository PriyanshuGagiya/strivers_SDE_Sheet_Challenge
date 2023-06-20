#include <bits/stdc++.h> 
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
//https://www.codingninjas.com/studio/problems/lca-of-two-nodes-in-a-bst_8230778?challengeSlug=striver-sde-challenge&leftPanelTab=1
TreeNode<int>* LCAinaBST(TreeNode<int>* root, TreeNode<int>* P, TreeNode<int>* Q)
{
	if(!root)
    {
        return NULL;
    }
    if(P->data<=root->data and root->data<=Q->data)
    {
        return root;
    }
    if(Q->data<=root->data and root->data<=P->data)
    {
        return root;
    }
    if(P->data<=root->data and root->data>=Q->data)
    {
        return LCAinaBST(root->left,P,Q);
    }
    return LCAinaBST(root->right,P,Q);
}
