#include <bits/stdc++.h> 
//https://www.codingninjas.com/studio/problems/palindrome-partitioning-ll_8230732?challengeSlug=striver-sde-challenge&leftPanelTab=1
bool ispalindrome(string &s)
{
    int i=0;
    int j=s.size()-1;
    while(i<=j)
    {
        if(s[i]!=s[j])
        {
            return 0;
        }
        i++;
        --j;
    }
    return 1;
}
int solve(int i,int n,string &str,vector<int>&dp)
{
    if(i==n)
    {
        return 0;
    }
    if(dp[i]!=-1) return dp[i];
    string curr="";
    int mini=INT_MAX;
    for(int j=i;j<n;++j)
    {
        curr+=str[j];
        if(ispalindrome(curr))
        {
            int partiton=1+solve(j+1,n,str,dp);
            mini=min(mini,partiton);
        }
    }
    return dp[i]=mini;
}
int palindromePartitioning(string str) 
{
        int n=str.size();
        vector<int>dp(n,-1);
        solve(0,n,str,dp);
        return dp[0]-1;
}
