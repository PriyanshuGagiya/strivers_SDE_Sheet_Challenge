#include <bits/stdc++.h> 
//https://www.codingninjas.com/studio/problems/bellman-ford_8230845?challengeSlug=striver-sde-challenge&leftPanelTab=1
int bellmonFord(int n, int m, int src, int dest, vector<vector<int>> &edges) 
{
    
    // Time Complexity: O(V*E)
    // Space Complexity: O(V)
    vector<int> dis(n + 1, 1e9);
    dis[src] = 0;
    for(int t = 1; t < n; t++)
    {
        bool noUpdate = true;
        for(int i = 0; i < m; i++)
        {
            if(dis[edges[i][0]] != 1e9 && dis[edges[i][1]] > dis[edges[i][0]] + edges[i][2])
            {
                dis[edges[i][1]] = dis[edges[i][0]] + edges[i][2];
                noUpdate = false;
            }
        }
        if(noUpdate) return dis[dest];
    }
   
    bool noUpdate = true;
    for(int i = 0; i < m; i++)
    {
        if(dis[edges[i][1]] > dis[edges[i][0]] + edges[i][2]){
            dis[edges[i][1]] = dis[edges[i][0]] + edges[i][2];
            noUpdate = false;
        }
    }
    
    if(noUpdate) return dis[dest];
    return INT_MIN;
}
