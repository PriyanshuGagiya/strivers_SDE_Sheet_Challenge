#include <bits/stdc++.h> 
//https://www.codingninjas.com/studio/problems/prim-s-mst_8230809?challengeSlug=striver-sde-challenge&leftPanelTab=1
vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    // Write your code here.
	vector<vector<int>>adj[n+1];
	for(int i=0;i<m;i++)
	{
		adj[g[i].first.first].push_back({g[i].first.second,g[i].second});
		adj[g[i].first.second].push_back({g[i].first.first,g[i].second});
	}
    priority_queue<vector<int>,vector<vector<int>>, greater<vector<int>>> pq;
	vector<pair<pair<int,int>,int>>ans;
	vector<int> vis(n+1, 0);
	// {wt, node,where it came from}
	pq.push({0, 1,0});
	int sum = 0;
	while (!pq.empty()) 
    {
		auto it = pq.top();
		pq.pop();
		int wt = it[0];
		int node = it[1];
		int p=it[2];
		if (vis[node]==1) continue;
		// add it to the mst
		vis[node] = 1;
		
        ans.push_back({{node,p},wt});
		if(p==0) ans.pop_back();
		for (auto it : adj[node]) 
		{
                  int adjNode = it[0];
                  int edW = it[1];
                  if (!vis[adjNode]) 
				  {
                    pq.push({edW, adjNode,node});
                  }
        }
    }
		return ans;
}
