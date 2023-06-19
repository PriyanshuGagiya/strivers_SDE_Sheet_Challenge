#include <bits/stdc++.h> 
//https://www.codingninjas.com/codestudio/problems/bfs-in-graph_8230763?challengeSlug=striver-sde-challenge&leftPanelTab=1
vector<int> BFS(int V, vector<pair<int, int>> edges)
{
    // Write your code here
    vector<int>adj[V];
   for(int i=0;i<edges.size();i++)
   {
       adj[edges[i].first].push_back(edges[i].second);
       adj[edges[i].second].push_back(edges[i].first);
   }
   for(int i=0;i<V;i++)
   {
       sort(adj[i].begin(),adj[i].end());
   }
   bool vis[V]={0};
   vector<int>ans;
   queue<int>q;
   q.push(0);
   vis[0]=1;
   while(q.size())
   {
       auto it=q.front();
       q.pop();
       ans.push_back(it);
       for(auto trav:adj[it])
       {
           if(!vis[trav])
           {
               vis[trav]=1;
               q.push(trav);
           }
       }
   }
   for(int i=0;i<V;i++)
   {
       if(!vis[i])
       {
           ans.push_back(i);
       }
   }
   return ans;
   
}
