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
//https://www.codingninjas.com/codestudio/problems/left-view-of-a-binary-tree_8230757?challengeSlug=striver-sde-challenge&leftPanelTab=1
vector<int> getLeftView(TreeNode<int> *root)
{
    if(root==NULL)
      return {};
    vector<int>ans;
    queue<TreeNode<int>*>q;
    q.push(root);
    while(q.size())
    {
        int n=q.size();
        for(int i=0;i<n;i++)
        {
            auto it=q.front();
            q.pop();
            if(it->left)
            {
                q.push(it->left);
            }
            if(it->right)
            {
                q.push(it->right);
            }
            if(i==0)
            {
                ans.push_back(it->data);
            }
        }
    }
    return ans;
}
