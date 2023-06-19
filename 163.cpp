//https://www.codingninjas.com/codestudio/problems/find-number-of-islands_8230692?challengeSlug=striver-sde-challenge&leftPanelTab=1
void dfs(int i,int j,int **arr,vector<vector<bool>>&vis,int n,int m)
{
   vis[i][j]=1;
   for(int r=-1;r<2;r++)
   {
      for(int c=-1;c<2;c++)
      {
         int nr=r+i;
         int nc=c+j;
         if(nr>=0 and nr<n and nc>=0 and nc<m and arr[nr][nc] and !vis[nr][nc])
         {
            dfs(nr,nc,arr,vis,n,m);
         }
      }
   }
}
int getTotalIslands(int** arr, int n, int m)
{
   // Write your code here.
   int ans=0;
   vector<vector<bool>>vis(n,vector<bool>(m,0));
   for(int i=0;i<n;i++)
   {
      for(int j=0;j<m;++j)
      {
         if(arr[i][j] and !vis[i][j])
         {
            dfs(i,j,arr,vis,n,m);
            ans++;
         }
      }
   }
   return ans;
}
