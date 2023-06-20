#include <bits/stdc++.h> 
//https://www.codingninjas.com/studio/problems/check-identical-trees_8230719?challengeSlug=striver-sde-challenge&leftPanelTab=1
/**********************************************************

    Following is the Binary Tree Node class structure:

    template <typename T>

    class BinaryTreeNode {
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

***********************************************************/

bool identicalTrees(BinaryTreeNode<int>* root1, BinaryTreeNode<int>* root2) 
{
    if(!root1 || !root2)
    {
        return root1==root2;
    }
    return (identicalTrees(root1->left,root2->left) and 
            identicalTrees(root1->right,root2->right) and 
            root1->data==root2->data);
}
