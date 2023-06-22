//https://www.codingninjas.com/studio/problems/floyd-warshall_8230846?challengeSlug=striver-sde-challenge
int floydWarshall(int n, int m, int src, int dest, vector<vector<int>> &edges) 
{
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
