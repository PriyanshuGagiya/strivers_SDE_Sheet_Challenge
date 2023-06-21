#include <bits/stdc++.h>
//https://www.codingninjas.com/studio/problems/subset-sum-equal-to-k_8230844?challengeSlug=striver-sde-challenge&leftPanelTab=1
bool solve(int i, int j, vector<int> &arr, vector<vector<int>> &dp) 
{
    if(j==0)
    {
        return 1;
    }
    if (i == 0)
    {
        return j==arr[i];
    }
    if(dp[i][j]!=-1) return dp[i][j];
    int take=0,nontake=solve(i-1,j,arr,dp);
    if(j>=arr[i])
    {
        take=solve(i-1,j-arr[i],arr,dp);
    }
    return dp[i][j]=take|nontake;

}
bool subsetSumToK(int n, int k, vector<int> &arr) 
{
   vector<vector<int>>dp(n,vector<int>(k+1,-1));
   return solve(n-1,k,arr,dp);
}
