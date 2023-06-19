#include<queue>
//https://www.codingninjas.com/codestudio/problems/cycle-detection-in-undirected-graph_8230798?challengeSlug=striver-sde-challenge&leftPanelTab=1
bool bfs(int node,bool vis[],vector<int>adj[])
{
    queue<pair<int,int>>q;
    q.push({node,-1});
    vis[node]=1;
    while(q.size())
    {
        auto it=q.front();
        q.pop();
        int i=it.first;
        int p=it.second;
        for(auto it : adj[i])
        {
                if(!vis[it])
                {
                    q.push({it,i});
                    vis[it]=1;
                }
                else if(it!=p)
                {
                    return 1;
                }
        }
    }
    return 0;
}
string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    // Write your code here.
    vector<int>adj[n+1];
    for(int i=0;i<m;i++)
    {
        adj[edges[i][0]].push_back(edges[i][1]);
        adj[edges[i][1]].push_back(edges[i][0]);
    }
    
    bool vis[n+1]={0};
    for(int i=1;i<n+1;i++)
    {
        if(!vis[i])
        {
          if (bfs(i, vis, adj)) {
            return "Yes";
          }
        }
    }
    return "No";
    
}
