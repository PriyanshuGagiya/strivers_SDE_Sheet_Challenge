#include <bits/stdc++.h> 
//https://www.codingninjas.com/studio/problems/bst-iterator_8230815?challengeSlug=striver-sde-challenge&leftPanelTab=1
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

class BSTiterator
{
    private: stack<TreeNode<int>*>st;
    public:
    BSTiterator(TreeNode<int> *root)
    {
        // write your code here
        pushAll(root);
    }

    int next()
    {
        auto it=st.top();
        st.pop();
        if(it->right)
        {
            pushAll(it->right);
        }
        return it->data;
    }

    bool hasNext()
    {
        // write your code here
        return st.size();
    }
    void pushAll(TreeNode<int>*root)
    {
        while(root)
        {
            st.push(root);
            root=root->left;
        }
    }
};


/*
    Your BSTIterator object will be instantiated and called as such:
    BSTIterator iterator(root);
    while(iterator.hasNext())
    {
       print(iterator.next());
    }
*/
