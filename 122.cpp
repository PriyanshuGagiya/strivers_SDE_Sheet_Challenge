#include <bits/stdc++.h> 
//https://www.codingninjas.com/studio/problems/height-of-the-binary-tree-from-inorder-and-level-order-traversal_8230730?challengeSlug=striver-sde-challenge&leftPanelTab=1
class Node {
public:
    int height;
    int leftIndex;
    int rightIndex;

    Node(int h, int li, int ri) {
        height = h;
        leftIndex = li;
        rightIndex = ri;
    }
};

int heightOfTheTree(vector<int>& inorder, vector<int>& levelOrder, int N)
{
	if(N==0) return 0;
	int ans=0;
	queue<Node>q;
	Node root(0,0,N-1);
	q.push(root);
	map<int,int>mp;
	for(int i=0;i<N;i++)
		mp[inorder[i]]=i;

	for(int i=0;i<N;i++)
	{
		Node curr=q.front();
		q.pop();
		
		int lindex = curr.leftIndex;
        int rindex = curr.rightIndex;
		int height=curr.height;
        int rootIndex=mp[levelOrder[i]];

		ans=max(ans,height);

		if(rootIndex - 1 >= lindex) 
		{
            Node leftSubTree(height + 1, lindex, rootIndex - 1);
            q.push(leftSubTree);
        }

        if(rootIndex + 1 <= rindex) {
            Node rightSubTree(height + 1, rootIndex + 1, rindex);
            q.push(rightSubTree);
        }
	}
	return ans;
}
