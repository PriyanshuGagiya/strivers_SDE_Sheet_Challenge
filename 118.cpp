#include <bits/stdc++.h> 
//https://www.codingninjas.com/studio/problems/vertical-order-traversal_8230758?challengeSlug=striver-sde-challenge&leftPanelTab=1
/************************************************************

Following is the Binary Tree node class
    
template <typename T = int>
class TreeNode
{
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T val)
    {
        this->data = val;
        left = NULL;
        right = NULL;
    }

    ~TreeNode()
    {
        if (left != NULL)
        {
            delete left;
        }
        if (right != NULL)
        {
            delete right;
        }
    }
};

************************************************************/

vector<int> verticalOrderTraversal(TreeNode<int> *root)
{
    //    Write your code here.
    queue<pair<TreeNode<int>*,pair<int,int>>>q;
    map<int,map<int,vector<int>>>node;
    vector<int>ans;
    if(root==NULL) return ans;
    q.push({root,{0,0}});
    while(!q.empty())
    {
        auto temp=q.front();
        TreeNode<int> * cur=temp.first;
        q.pop();
        int l=temp.second.first;
        int r=temp.second.second;
        node[l][r].push_back(cur->data);
        if(cur->left)
        {
            q.push({cur->left,{l-1,r+1}});
        }
        if(cur->right)
        {
            q.push({cur->right,{l+1,r+1}});
        }
    }
    for(auto p:node)
    {
        
        for(auto q:p.second)
        {
            ans.insert(ans.end(),q.second.begin(),q.second.end());
        }
        
    }
    return ans;
        
}
