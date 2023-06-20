#include <bits/stdc++.h> 
//https://www.codingninjas.com/studio/problems/binary-tree-zigzag-traversal_8230796?challengeSlug=striver-sde-challenge&leftPanelTab=1
/*************************************************************

    Following is the Binary Tree node structure

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

vector<int> zigZagTraversal(BinaryTreeNode<int> *root)
{
    // Write your code here!
    vector<int>ans;
    if(!root) return ans;
    queue<BinaryTreeNode<int> *>q;
    q.push(root);
    bool rev=false;
    while(q.size())
    {
        int n=q.size();
        vector<int>temp(n);
        for(int i=0;i<n;i++)
        {
            auto curr=q.front();
            q.pop();
            if(rev)
            {
                temp[n-1-i]=curr->data;
            }
            else
            {
                temp[i]=curr->data;
            }
            if(curr->left)
            {
                q.push(curr->left);
            }
            if(curr->right)
            {
                q.push(curr->right);
            }
        }
        ans.insert(ans.end(),temp.begin(),temp.end());
        rev=!rev;
    }
    return ans;
}
