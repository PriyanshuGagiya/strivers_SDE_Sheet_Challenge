#include <bits/stdc++.h> 
//https://www.codingninjas.com/studio/problems/construct-bst-from-preorder-traversal_8230850?challengeSlug=striver-sde-challenge&leftPanelTab=1
/*************************************************************

    Following is the Binary Tree node structure

    template <typename T>

    class TreeNode{
    public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
        ~TreeNode() {
            if (left){
                delete left;
            }
            if (right){
                delete right;
            }
        }
    };

*************************************************************/
int ind;
TreeNode<int>* solve(vector<int> &preOrder,int upbound)
{
    if(ind>=preOrder.size()) return NULL;
    if(preOrder[ind]<upbound)
    {
        TreeNode<int>* root=new TreeNode<int>(preOrder[ind++]);
        root->left=solve(preOrder,root->data);
        root->right=solve(preOrder,upbound);
        return root;
    }
    return NULL;
    
}
TreeNode<int>* preOrderTree(vector<int> &preOrder){
    // Write your code here.
    ind=0;
    return solve(preOrder,INT_MAX);
}
