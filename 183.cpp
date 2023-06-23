#include <bits/stdc++.h> 
//https://www.codingninjas.com/studio/problems/word-break_8230808?challengeSlug=striver-sde-challenge&leftPanelTab=1
int solve(int i,int n,string&target,unordered_map<string,int>&mp,vector<int>&dp)
{
    if(i==n)
    {
        return 1;
    }
    if(dp[i]!=-1) return dp[i];
    string curr="";
    for(int j=i;j<n;j++)
    {
        curr+=target[j];
        if(mp.find(curr)!=mp.end())
        {
            if(solve(j+1,n,target,mp,dp))
            {
                return 1;
            }
        }
    }
    return dp[i]=0;
}
bool wordBreak(vector < string > & arr, int n, string & target) 
{
    // Write your code here.
    unordered_map<string,int>mp;
    for(int i=0;i<n;i++)
    {
        mp[arr[i]]++;
    }
    vector<int>dp(target.size(),-1);
    solve(0,target.size(),target,mp,dp);
    return dp[0];
}
