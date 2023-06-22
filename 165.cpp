#include<bits/stdc++.h>
//https://www.codingninjas.com/studio/problems/strongly-connected-components-tarjan-s-algorithm_8230789?challengeSlug=striver-sde-challenge&leftPanelTab=1
void topo(int node, vector<int> &vis, vector<int> adj[],stack<int> &st) 
{
        vis[node] = 1;
        for (auto it : adj[node]) 
        {
            if (!vis[it]) 
            {
                topo(it, vis, adj, st);
            }
        }

        st.push(node);
}
void kosaraju(int node, vector<int> &vis, vector<int>transpose[],vector<int>&temp) 
{
    vis[node] = 1;
    temp.push_back(node);
    for (auto it : transpose[node]) 
    {
            if (!vis[it]) 
            {
                kosaraju(it, vis, transpose,temp);
            }
    }
}
vector<vector<int>> stronglyConnectedComponents(int n, vector<vector<int>> &edges)
{
    // Write your code here.
    vector<int> adj[n];
    vector<int>transpose[n];
    for (auto it : edges) 
    {
        adj[it[0]].push_back(it[1]);
        transpose[it[1]].push_back(it[0]);
    }
    vector<int> vis(n, 0);
    stack<int>st;
    for (int i = 0; i < n; i++) 
    {
            if (!vis[i]) 
            {
                topo(i, vis, adj, st);
            }
    }
    for(int i=0;i<n;i++) vis[i]=0;
    vector<vector<int>>ans;
    while (!st.empty()) 
    {
        int node = st.top();
        st.pop();
        if (!vis[node]) 
        {
            vector<int>temp;
            kosaraju(node, vis, transpose,temp);
            ans.push_back(temp);
        }
    }
    return ans;
}
