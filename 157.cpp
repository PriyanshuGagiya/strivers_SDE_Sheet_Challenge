#include <bits/stdc++.h> 
//https://www.codingninjas.com/studio/problems/clone-graph_8230812?challengeSlug=striver-sde-challenge&leftPanelTab=1
/***************************************************************************

	Class for graph node is as follows:

	class graphNode
	{
		public:
    		int data;
    	vector<graphNode *> neighbours;
    	graphNode()
    	{
        	data = 0;
        	neighbours = vector<graphNode *>();
    	}

    	graphNode(int data)
    	{
        	data = data;
        	neighbours = vector<graphNode *>();
    	}

    	graphNode(int data, vector<graphNode *> neighbours)
    	{
        	data = data;
        	this->neighbours = neighbours;
    	}
	};

******************************************************************************/

graphNode *cloneGraph(graphNode *node) {
  // Write your code here.
  	unordered_map<graphNode *, graphNode *> mp;
  	queue<graphNode *> q;
  	q.push(node);
	mp[node]=new graphNode(node->data);
  	while (q.size())
	{
		auto it=q.front();
		q.pop();
		for(auto n : it->neighbours)
		{
			if(mp.find(n)==mp.end())
			{
				mp[n]=new graphNode(n->data);
				q.push(n);
			}
			mp[it]->neighbours.push_back(mp[n]);
		}
	}
	return mp[node];
}
