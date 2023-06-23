#include <bits/stdc++.h> 
//https://www.codingninjas.com/studio/problems/connect-nodes-at-same-level_8230790?challengeSlug=striver-sde-challenge&leftPanelTab=1
/*
    ----------------- Binary Tree node class for reference -----------------

    template <typename T>
    class BinaryTreeNode {
        public : 
            T data;
            BinaryTreeNode<T> *left;
            BinaryTreeNode<T> *right;
            BinaryTreeNode<T> *next;

            BinaryTreeNode(T data) {
                this -> data = data;
                left = NULL;
                right = NULL;
                next = NULL;
            }
    };
*/

void connectNodes(BinaryTreeNode< int > *root) 
{
    // Write your code here.
    queue<BinaryTreeNode< int > *>q;
    q.push(root);
    while(q.size())
    {
        int n=q.size();
        for(int i=0;i<n;i++)
        {
            auto it=q.front();
            q.pop();
            if(i==n-1)
            it->next=NULL;
            else
            it->next=q.front();
            if(it->left)
            {
                q.push(it->left);
            }
            if(it->right)
            {
                q.push(it->right);
            }
        }
    }
}
