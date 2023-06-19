#include<queue>
//https://www.codingninjas.com/codestudio/problems/rotting-oranges_8230701?challengeSlug=striver-sde-challenge&leftPanelTab=1
int minTimeToRot(vector<vector<int>>& grid, int n, int m)
{
    // Write your code here. 
    queue<vector<int>>q;
    int one=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(grid[i][j]==2)
            {
              q.push({0, i, j});
            }
            else if(grid[i][j])
            {
                one++;
            }
        }
    }
    int ans=0;
    int dr[]={1,-1,0,0};
    int dc[]={0,0,1,-1};
    while(q.size())
    {
        auto it=q.front();
        q.pop();
        ans=max(ans,it[0]);
        int r=it[1];
        int c=it[2];
        int s=it[0];
        for(int i=0;i<4;i++)
        {
            int nr=r+dr[i],nc=dc[i]+c;
            if(nr>=0 and nr<n and nc>=0 and nc<m and grid[nr][nc]==1)
            {
                one--;
                grid[nr][nc]=2;
                q.push({s+1,nr,nc});
            }

        }

    }
    if(one)
    {
        return -1;
    }
    return ans;
}
