#include <bits/stdc++.h> 
//https://www.codingninjas.com/studio/problems/boundary-traversal-of-binary-tree_8230712?challengeSlug=striver-sde-challenge&leftPanelTab=1
/************************************************************

    Following is the Binary Tree node structure:
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/
bool isLeaf(TreeNode<int>* root) 
{
  return !root -> left && !root -> right;
}
void addleft(TreeNode<int>* root, vector < int > & ans) 
{
  TreeNode<int>*cur = root -> left;
  while (cur) 
  {
    if (!isLeaf(cur)) ans.push_back(cur -> data);
    if (cur -> left) cur = cur -> left;
    else cur = cur -> right;
  }
}
void addright(TreeNode<int>* root, vector < int > & ans) {
  TreeNode<int>*cur = root -> right;
  vector < int > tmp;
  while (cur) 
  {
    if (!isLeaf(cur)) tmp.push_back(cur -> data);
    if (cur -> right) cur = cur -> right;
    else cur = cur -> left;
  }
  for (int i = tmp.size() - 1; i >= 0; --i) 
  {
    ans.push_back(tmp[i]);
  }
}

void addleaf(TreeNode<int>* root, vector < int > & ans) 
{
  if (isLeaf(root)) 
  {
    ans.push_back(root -> data);
    return;
  }
  if (root -> left) addleaf(root -> left, ans);
  if (root -> right) addleaf(root -> right, ans);
}

vector<int> traverseBoundary(TreeNode<int>* root)
{
    // Write your code here.
    vector<int>ans;
    if(!isLeaf(root))
    {
            ans.push_back(root->data);
    }
    addleft(root,ans);
    addleaf(root,ans);
    addright(root,ans);
    return ans;
}
