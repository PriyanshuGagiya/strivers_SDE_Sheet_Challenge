//https://www.codingninjas.com/studio/problems/diameter-of-binary-tree_8230762?challengeSlug=striver-sde-challenge&leftPanelTab=3
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
int solve(TreeNode<int>*root,int &ans)
{
    if(!root) return 0;
    int l=0,r=0;
    if(root->left)
    {
        l=solve(root->left,ans);
    }
    if(root->right)
    {
        r=solve(root->right,ans);
    }
    ans=max(ans,l+r);
    return 1+max(l,r);
}
int diameterOfBinaryTree(TreeNode<int> *root)
{
	// Write Your Code Here.
    int ans=0;
    solve(root,ans);
    return ans;
}
