#include <bits/stdc++.h> 
//https://www.codingninjas.com/studio/problems/size-of-largest-bst-in-binary-tree_8230743?challengeSlug=striver-sde-challenge&leftPanelTab=1
/************************************************************

    Following is the Binary Tree node structure
    
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
class node{
public:
    int mini;
    int maxi;
    bool isBST;
    int siz;
};
node solve(TreeNode<int>* root, int &ans)
{
    
    if(root == NULL) 
    return {INT_MAX, INT_MIN, true, 0};

    node left = solve(root->left, ans);
    node right = solve(root->right, ans);

    node curr;
    curr.mini = min(left.mini, root->data);
    curr.maxi = max(right.maxi, root->data);
    curr.siz = left.siz + right.siz + 1;

    if(left.isBST and right.isBST and 
    (root->data > left.maxi and root->data < right.mini) ) 
    {
        curr.isBST = true;
    }
    else curr.isBST = false;

    if(curr.isBST == true) {ans = max(ans, curr.siz);}
    
    return curr;
}
int largestBST(TreeNode<int>* root) 
{
    // Write your code here.
    int ans=0;
    node temp=solve(root,ans);
    return ans;

}
