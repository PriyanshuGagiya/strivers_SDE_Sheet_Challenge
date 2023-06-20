#include <bits/stdc++.h> 
//https://www.codingninjas.com/studio/problems/convert-a-given-binary-tree-to-doubly-linked-list_8230744?challengeSlug=striver-sde-challenge
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
void inorder(BinaryTreeNode<int>* root,vector<BinaryTreeNode<int>*>&ino)
{
    if(!root) return;
    inorder(root->left, ino);
    ino.push_back(root);
    inorder(root->right, ino);
}
BinaryTreeNode<int>* BTtoDLL(BinaryTreeNode<int>* root) 
{
    // Write your code here
    if(!root) return nullptr;
    vector<BinaryTreeNode<int>*>ino;
    inorder(root,ino);
    BinaryTreeNode<int>*curr=ino[0];
    BinaryTreeNode<int>*prev=NULL;
    int i=1;
    int n=ino.size();
    while(i<n)
    {
        curr->left=prev;
        prev=curr;
        curr->right=ino[i++];
        curr=curr->right;
    }
    return ino[0];
}
