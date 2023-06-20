//https://www.codingninjas.com/studio/problems/construct-binary-tree-from-inorder-and-postorder-traversal_8230837?challengeSlug=striver-sde-challenge
/************************************************************
   
   Following is the TreeNode class structure
   
   class TreeNode<T>
   { 
   public:
        T data; 
        TreeNode<T> *left;
        TreeNode<T> *right;
   
        TreeNode(T data) 
  		{ 
            this -> data = data; 
            left = NULL; 
            right = NULL; 
        }
   };
   
   
 ************************************************************/
 #include <bits/stdc++.h> 
TreeNode<int>* func(vector<int> &inorder, vector<int> &postorder, int is, int ie, int ps, int pe, 
unordered_map<int,int>& mp)
{
    if (ps > pe || is > ie) return NULL; 
    TreeNode<int>* root = new TreeNode<int>(postorder[pe]);
    int ind = mp[root->data];
    int sz = ind - is;
    root->left = func(inorder, postorder, is, ind - 1, ps, ps+sz-1, mp);
    root->right = func(inorder, postorder, ind + 1, ie, ps+sz, pe-1, mp);
    return root;
}

TreeNode<int>* getTreeFromPostorderAndInorder(vector<int>& postOrder, vector<int>& inOrder) 
{
	// Write your code here.
    unordered_map<int, int> mp;
    int n = inOrder.size();
    for (int i = 0; i < n; i++)
    {
        mp[inOrder[i]] = i;
    }
    return func(inOrder, postOrder, 0, n - 1, 0, n - 1, mp);
}
