#include <bits/stdc++.h> 
/*************************************************************
 
    Following is the Binary Tree node structure.

    class BinaryTreeNode 
    {
    public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/
//https://www.codingninjas.com/codestudio/problems/bottom-view-of-binary-tree_8230745?challengeSlug=striver-sde-challenge&leftPanelTab=3
vector<int> bottomView(BinaryTreeNode<int> * root)
{

    vector<int>ans;
    if(!root) return ans;
   queue<pair<BinaryTreeNode<int>*,int>>q;
   q.push({root, 0});
   map<int,vector<int>>mp;
   while(q.size())
   {
       auto it=q.front();
       q.pop();
       int s=it.second;
       mp[s].push_back(it.first->data);
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
       ans.push_back(it.second.back());
   }
   return ans;
}
