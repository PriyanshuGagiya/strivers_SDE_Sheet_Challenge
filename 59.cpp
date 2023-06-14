#include <bits/stdc++.h> 
//https://www.codingninjas.com/codestudio/problems/rat-in-a-maze-all-paths_8230705?challengeSlug=striver-sde-challenge&leftPanelTab=1
void solve(int i,int j,vector<vector<int>>&vis,vector<vector<int>>&maze,int n,vector<vector<int>>&ans)
{
    
   if (i == n - 1 && j == n - 1) 
   {
     vis[i][j]=1;
     vector<int>temp;
      for(int i=0;i<n;i++)
      {
        for(int j=0;j<n;j++)
        {
          temp.push_back(vis[i][j]);
        }
      }
      ans.push_back(temp);
      vis[i][j]=0;
      return;
    }

    if (i + 1 < n && !vis[i + 1][j] && maze[i + 1][j] == 1) 
    {
      vis[i][j] = 1;
      solve(i + 1, j, vis,maze,n,ans);
      vis[i][j] = 0;
    }

    
    if (j - 1 >= 0 && !vis[i][j - 1] && maze[i][j - 1] == 1) {
      vis[i][j] = 1;
      solve(i, j - 1, vis,maze,n,ans);
      vis[i][j] = 0;
    }

    
    if (j + 1 < n && !vis[i][j + 1] && maze[i][j + 1] == 1) {
      vis[i][j] = 1;
      solve(i, j + 1, vis,maze,n,ans);
      vis[i][j] = 0;
    }

    
    if (i - 1 >= 0 && !vis[i - 1][j] && maze[i - 1][j] == 1) {
      vis[i][j] = 1;
      solve(i - 1, j, vis,maze,n,ans);
      vis[i][j] = 0;
    }
}
vector<vector<int> > ratInAMaze(vector<vector<int> > &maze, int n)
{
  vector<vector<int>>ans;
  vector<vector<int>>vis(n,vector<int>(n,0));
  solve(0,0,vis,maze,n,ans);
  return ans;
  
}
