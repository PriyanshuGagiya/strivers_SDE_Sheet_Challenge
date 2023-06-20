#include <queue>
//https://www.codingninjas.com/studio/problems/flood-fill-algorithm_8230806?challengeSlug=striver-sde-challenge&leftPanelTab=1
vector<vector<int>> floodFill(vector<vector<int>> &image, int x, int y, int newColor)
{
    // Write your code here
    
    queue<pair<int,int>>q;
    int pastColor=image[x][y];
    if(pastColor==newColor) return image;
    int dr[]={0,0,1,-1};
    int dc[]={1,-1,0,0};
    q.push({x,y});
    image[x][y]=newColor;
    int n=image.size(),m=image[0].size();
    while(q.size())
    {
        int r=q.front().first;
        int c=q.front().second;
        q.pop();
        for(int i=0;i<4;i++)
        {
            int nr=r+dr[i],nc=c+dc[i];
            if(nr>=0 and nr<n and nc>=0 and nc<m and image[nr][nc]==pastColor)
            {
                image[nr][nc]=newColor;
                q.push({nr,nc});
            }
        }
    }
    return image;
}
