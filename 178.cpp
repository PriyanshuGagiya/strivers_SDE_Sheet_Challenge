#include <bits/stdc++.h> 
//https://www.codingninjas.com/studio/problems/minimum-path-sum_8230791?challengeSlug=striver-sde-challenge
int solve(int i,int j,vector<vector<int>> &grid,vector<vector<int>> &dp,int n,int m)
{
    if(i==n-1 and j==m-1)
    {
        return grid[i][j];
    }
    if(i>=n || j>=m)
    {
        return 1e9;
    }
    if(dp[i][j]!=-1)
    {
        return dp[i][j];
    }
    int left=grid[i][j]+solve(i+1,j,grid,dp,n,m);
    int down=grid[i][j]+solve(i,j+1,grid,dp,n,m);
    return dp[i][j]=min(left,down);
}
int minSumPath(vector<vector<int>> &grid) 
{
    // Write your code here.
    int n=grid.size(),m=grid[0].size();
    vector<vector<int>>dp(n,vector<int>(m,-1));
    return solve(0,0,grid,dp,n,m);
}
