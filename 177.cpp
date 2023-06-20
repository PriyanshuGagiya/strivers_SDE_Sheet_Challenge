#include <bits/stdc++.h> 
//https://www.codingninjas.com/studio/problems/matrix-chain-multiplication_8230769?challengeSlug=striver-sde-challenge&leftPanelTab=1
int solve(int i,int j,vector<int>&arr,vector<vector<int>>&dp)
{
    if(i==j) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    int maxi=INT_MAX;
    for(int k=i;k<j;k++)
    {
        int temp=(arr[i-1]*arr[k]*arr[j])+solve(i,k,arr,dp)+solve(k+1,j,arr,dp);
        maxi=min(maxi,temp);
    }
    return dp[i][j]=maxi;
}
int matrixMultiplication(vector<int> &arr, int N)
{
    // Write your code here.
    vector<vector<int>>dp(N,vector<int>(N,-1));
    return solve(1,N-1,arr,dp);
}
