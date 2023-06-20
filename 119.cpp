#include <bits/stdc++.h> 
//https://www.codingninjas.com/studio/problems/path-in-a-tree_8230860?challengeSlug=striver-sde-challenge&leftPanelTab=1
/*   
    template <typename T = int>
	class TreeNode
	{
		public:
		T data;
		TreeNode<T> *left;
		TreeNode<T> *right;

		TreeNode(T data)
		{
			this->data = data;
			left = NULL;
			right = NULL;
		}

		~TreeNode()
		{
			if (left != NULL)
			{
		  		delete left;
			}
			if (right != NULL)
			{
			 	delete right;
			}
		}
	};
*/

bool solve(TreeNode<int> *root, int x,vector<int>&ans)
{
	if(!root) return false;
	if(root->data==x)
	{
		ans.push_back(x);
		return true;
	}
	if(root->left)
	{
		ans.push_back(root->data);
		if(solve(root->left,x,ans))
		{
			return true;
		}
		ans.pop_back();
	}
	if(root->right)
	{
		ans.push_back(root->data);
		if(solve(root->right,x,ans))
		{
			return true;
		}
		ans.pop_back();
	}
	return false;
}
vector<int> pathInATree(TreeNode<int> *root, int x)
{
    // Write your code here.
	vector<int> ans;
	solve(root,x,ans);
	return ans;
}
