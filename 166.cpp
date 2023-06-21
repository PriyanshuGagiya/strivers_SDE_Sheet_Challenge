#include <bits/stdc++.h> 
//https://www.codingninjas.com/studio/problems/dijkstra-s-shortest-path_8230755?challengeSlug=striver-sde-challenge&leftPanelTab=1
vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) 
{
    vector<pair<int,int>>adj[vertices];
    for(auto it: vec)
    {
        adj[it[0]].push_back({it[1],it[2]});
        adj[it[1]].push_back({it[0],it[2]});
    }
    vector<int> dis(vertices,INT_MAX);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
    dis[source] = 0;
    pq.push({0,source});

    while(!pq.empty())
    {
        auto temp = pq.top();
        pq.pop();
        for(auto it: adj[temp.second])
        {
            if(temp.first + it.second < dis[it.first])
            {
                dis[it.first] = temp.first + it.second;
                pq.push({temp.first + it.second,it.first});
            }
        }
    }
    return dis;
}
