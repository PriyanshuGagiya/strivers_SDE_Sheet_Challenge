#include <bits/stdc++.h>
//https://www.codingninjas.com/studio/problems/cut-logs_8230782?challengeSlug=striver-sde-challenge&leftPanelTab=1
int solve(int k,int n,vector<vector<int>>&dp)
{
    if(n==1||n==0) return n;
    if(k==1) return n;

    if(dp[k][n]!=-1) return dp[k][n];

    int low=1,high=n;
    int ans=1e9;
    while(low<=high)
    {
        int mid=low+(high-low)/2;
        int down=solve(k-1,mid-1,dp);
        int up=solve(k,n-mid,dp);
       
        if(down<up)
        {
            ans=min(ans,1+up);
            low=++mid;
        }
        else
        {
            ans=min(ans,1+down);
            high=--mid;
        }
    }
    return dp[k][n]=ans;
}
int cutLogs(int k, int n)
{
    // Write your code here.
    vector<vector<int>>dp(k+1,vector<int>(n+1,-1));
    return solve(k,n,dp);
}
