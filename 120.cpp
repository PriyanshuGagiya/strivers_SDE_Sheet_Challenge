#include <bits/stdc++.h> 
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
//https://www.codingninjas.com/studio/problems/maximum-width-in-binary-tree_8230710?challengeSlug=striver-sde-challenge&leftPanelTab=1
int getMaxWidth(TreeNode<int> *root)
{
    // Write your code here.
    if(!root) return 0;
    queue<TreeNode<int>*>q;
    q.push(root);
    int ans=1;
    while(q.size())
    {
        int n=q.size();
      
        for(int i=0;i<n;i++)
        {
            TreeNode<int>*node=q.front();
            q.pop();
            if(node->left)
            {
                q.push(node->left);
            }
            if(node->right)
            {
                q.push(node->right);
            }
        }
        ans=max(ans,n);
    }
    return ans;
}
