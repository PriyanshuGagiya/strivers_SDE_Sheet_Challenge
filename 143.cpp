#include <bits/stdc++.h> 
//https://www.codingninjas.com/studio/problems/floor-in-bst_8230753?challengeSlug=striver-sde-challenge&leftPanelTab=1
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

int floorInBST(TreeNode<int> * root, int X)
{
    // Write your code here.
    int floor=-1;
    TreeNode<int>* trav=root;
    while(trav)
    {
        if(trav->val<=X)
        {
            floor=trav->val;
            trav=trav->right;
        }
        else
        {
            trav=trav->left;
        }
    }
    return floor;
}
