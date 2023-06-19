#include <bits/stdc++.h> 
//https://www.codingninjas.com/codestudio/problems/topological-sort_8230784?challengeSlug=striver-sde-challenge&leftPanelTab=1
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  
{
    int deg[v] = {0};
  vector<int> adj[v];
  for (int i = 0; i < e; i++) 
  {
    adj[edges[i][0]].push_back(edges[i][1]);
    deg[edges[i][1]]++;
  }
  queue<int>q;
  vector<int>ans;
  for(int i=0;i<v;++i)
  {
    if(deg[i]==0)
    {
      q.push(i);
    }
  }
  while(q.size())
  {
      int node=q.front();
      q.pop();
      ans.push_back(node);
      for(auto it:adj[node])
      {
        
          deg[it]--;
          if (!deg[it]) {
            q.push(it);
          }
        
      }
  }
  
  return ans;
}
