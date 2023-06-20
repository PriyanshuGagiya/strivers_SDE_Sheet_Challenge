//https://www.codingninjas.com/studio/problems/symmetric-tree_8230686?challengeSlug=striver-sde-challenge&leftPanelTab=1
/*****************************************************

    Following is the Binary Tree node structure:
    
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
        
        ~BinaryTreeNode() {
            if(left) 
                delete left;
            if(right) 
                delete right;
        }
    };

******************************************************/

bool solve(BinaryTreeNode<int>* r1,BinaryTreeNode<int>* r2)
{
    if(!r1 || !r2)
    {
        return r1==r2;
    }
    if(r1->data==r2->data)
    {
        return solve(r1->left,r2->right) and solve(r2->right,r1->left);
    }
    return 0;
}
bool isSymmetric(BinaryTreeNode<int>* root)
{
    // Write your code here.    
    return solve(root,root);
}
