#include <queue>
//https://www.codingninjas.com/codestudio/problems/detect-cycle-in-a-directed-graph_8230794?challengeSlug=striver-sde-challenge&leftPanelTab=1
int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) 
{
  int deg[n + 1] = {0};
  vector<int> adj[n + 1];
  for (int i = 0; i < edges.size(); i++) 
  {
    adj[edges[i].first].push_back(edges[i].second);
    deg[edges[i].second]++;
  }
  queue<int>q;
  for(int i=1;i<n+1;++i)
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
      for(auto it:adj[node])
      {
        if(deg[it])
        {
          deg[it]--;
          if (!deg[it]) {
            q.push(it);
          }
        }
      }
  }
  for(int i=1;i<n+1;i++)
  {
    if(deg[i]) return 1;
  }
  return 0;
}
