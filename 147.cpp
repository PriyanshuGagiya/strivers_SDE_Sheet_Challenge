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
// better approach
#include <bits/stdc++.h> 
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
class BSTiterator
{
    private: stack<BinaryTreeNode<int>*>st;
    public:
    bool rev=1;
    BSTiterator(BinaryTreeNode<int> *root,bool r)
    {
        // write your code here
        pushAll(root);
        rev=r;
    }

    int next()
    {
        if(rev)
        {
            auto it=st.top();
            st.pop();
            if(it->left)
            {
                pushAll(it->left);
            }
            return it->data;
        }
        else
        {
        auto it=st.top();
        st.pop();
        if (it->right) {
          pushAll(it->right);
        }
        return it->data;
        }
    }

    void pushAll(BinaryTreeNode<int>*root)
    {
        if(rev)
        {
            while (root) 
            {
                st.push(root);
                root = root->right;
            }
        }
        else
        {
          while (root) {
            st.push(root);
            root = root->left;
          }
        }
    }
};
bool pairSumBst(BinaryTreeNode<int> *root, int k)
{
    // Write your code here
    BSTiterator l(root,false);
    BSTiterator h(root,true);
    int lo=l.next();
    int hi=h.next();
    while(lo<hi)
    {
        int sum=lo+hi;
        if(sum==k)
        {
            return 1;
        }
        if(sum<k)
        {
            lo=l.next();;
        }
        else
        {
            hi=h.next();
        }

    }
    return 0;
}
