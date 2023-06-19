//https://www.codingninjas.com/codestudio/problems/check-bipartite-graph_8230761?challengeSlug=striver-sde-challenge&leftPanelTab=1
bool dfs(int i,int col,int vis[],vector<vector<int>>& graph)
{
        vis[i]=col;
        for(int j=0;j<graph.size();j++)
        {
			if(graph[i][j])
			{
			
				if(vis[j]==-1)
				{
					if(dfs(j,!col,vis,graph))
					{
						return true;
					}
				}
				else if(vis[j]==vis[i])
				{
					return true;
				}
			}
        }
        return false;
}
bool isGraphBirpatite(vector<vector<int>> &graph) 
{
	// Write your code here.
	int v=graph.size();
    int vis[v];
    for(int i=0;i<v;i++) vis[i]=-1;
    for(int i=0;i<v;i++)
    {
        if(vis[i]==-1)
        {
        if(dfs(i,0,vis,graph))
        {
            return false;
        }
        }
    }
    return true;
}
