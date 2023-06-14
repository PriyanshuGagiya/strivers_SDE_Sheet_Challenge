#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure:

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
//https://www.codingninjas.com/codestudio/problems/top-view-of-binary-tree_8230721?challengeSlug=striver-sde-challenge&leftPanelTab=1
vector<int> getTopView(TreeNode<int> *root) 
{
    queue<pair<TreeNode<int>*,int>>q;
    vector<int>ans;
    if(!root) return ans;
    q.push({root, 0});
    map<int,int>mp;
    while(q.size())
    {
        auto it=q.front();
        q.pop();
        int s=it.second;
        if(mp.find(s)==mp.end())
        {
            mp[s]=it.first->val;
        }
        if(it.first->left)
        {
            q.push({it.first->left,s-1});
        }
         if(it.first->right)
        {
            q.push({it.first->right,s+1});
        }
    }
    for(auto it : mp)
    {
        ans.push_back(it.second);
    }
    return ans;
}
