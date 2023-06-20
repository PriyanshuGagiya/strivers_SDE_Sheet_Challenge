#include <bits/stdc++.h> 
//https://www.codingninjas.com/studio/problems/kth-smallest-node-in-bst_8230751?challengeSlug=striver-sde-challenge&leftPanelTab=1
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
TreeNode<int>* solve(TreeNode<int>*root,int &k)
{
    if(root==NULL)
	return NULL;
	
	TreeNode<int>* left=solve(root->left,k);
	if(left!=NULL)
	return left;
	k--;
	
	if(k==0)
	return root;
	
	return solve(root->right,k);
}
int kthSmallest(TreeNode<int> *root, int k)
{
	//	Write the code here.
    TreeNode<int>* ans=solve(root,k);
    if(ans)
    return ans->data;
    return -1;
}
