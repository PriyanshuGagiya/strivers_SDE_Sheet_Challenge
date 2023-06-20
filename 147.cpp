#include <bits/stdc++.h> 
//https://www.codingninjas.com/studio/problems/pair-sum-in-bst_8230756?challengeSlug=striver-sde-challenge&leftPanelTab=1
/**********************************************************

    Following is the Binary Tree Node structure:

    template <typename T>
    class BinaryTreeNode {
        public: 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }

        ~BinaryTreeNode() {
            if (left)
                delete left;
            if (right)
                delete right;
        }
    };
***********************************************************/
void solve(BinaryTreeNode<int> *root,vector<int>&arr)
{
    if(!root) return ;
    solve(root->left,arr);
    arr.push_back(root->data);
    solve(root->right,arr);
}
bool pairSumBst(BinaryTreeNode<int> *root, int k)
{
    // Write your code here
    vector<int>arr;
    solve(root,arr);
    int lo=0;
    int hi=arr.size()-1;
    while(lo<hi)
    {
        int sum=arr[lo]+arr[hi];
        if(sum==k)
        {
            return 1;
        }
        if(sum<k)
        {
            lo++;
        }
        else
        {
            hi--;
        }

    }
    return 0;
}
