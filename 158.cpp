//https://www.codingninjas.com/codestudio/problems/dfs-traversal_8230690?challengeSlug=striver-sde-challenge&leftPanelTab=1
void dfs(int node,vector<int>adj[],vector<int>&temp,bool vis[])
{
    temp.push_back(node);
    vis[node]=1;
    for(auto it : adj[node])
    {
        if(!vis[it])
        {
            dfs(it,adj,temp,vis);
        }
    }
}
vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
   vector<int>adj[V];
   for(int i=0;i<E;i++)
   {
       adj[edges[i][0]].push_back(edges[i][1]);
       adj[edges[i][1]].push_back(edges[i][0]);
   }
   bool vis[V]={0};
   vector<vector<int>>ans;
   for(int i=0;i<V;i++)
   {
       if(!vis[i])
       {
           vector<int>temp;
           dfs(i,adj,temp,vis);
           ans.push_back(temp);
       }
   }
   return ans;
}
