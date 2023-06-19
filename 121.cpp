#include <bits/stdc++.h> 
//https://www.codingninjas.com/codestudio/problems/level-order-traversal_8230716?challengeSlug=striver-sde-challenge&leftPanelTab=1
/************************************************************

    Following is the BinaryTreeNode class structure

    template <typename T>
    class BinaryTreeNode {
       public:
        T val;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
#include<queue>
#include<vector>
vector<int> getLevelOrder(BinaryTreeNode<int> *root)
{
    //  Write your code here.
    if(!root)
      return {};
    queue<BinaryTreeNode<int>*>q;
    q.push(root);
    vector<int>ans;
    while(q.size())
    {
        auto it=q.front();
        ans.push_back(it->val);
        q.pop();
        if(it->left)
        q.push(it->left);
        if(it->right)
        q.push(it->right);
    }
    return ans;
}
