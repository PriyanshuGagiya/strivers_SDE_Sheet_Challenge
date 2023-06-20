#include <bits/stdc++.h> 
//https://www.codingninjas.com/studio/problems/convert-sorted-array-to-bst_8230836?challengeSlug=striver-sde-challenge&leftPanelTab=1
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;
        
        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
TreeNode<int>*solve(vector<int>&arr,int s,int e)
{
    if(e<s) return NULL;
    int mid=(s+e)/2;
    TreeNode<int>*root=new TreeNode<int>(arr[mid]);
    root->left=solve(arr,s,mid-1);
    root->right=solve(arr,mid+1,e);
    return root;
}
TreeNode<int>* sortedArrToBST(vector<int> &arr, int n)
{
    // Write your code here.
    return solve(arr,0,n-1);
}
