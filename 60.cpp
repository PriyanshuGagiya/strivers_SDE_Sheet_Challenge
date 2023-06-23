#include <bits/stdc++.h> 
//https://www.codingninjas.com/studio/problems/word-break-ii_8230786?challengeSlug=striver-sde-challenge&leftPanelTab=1
void solve(int i,int n,string &target,unordered_map<string,int>&mp,
            vector<string>&ans,string put)
{
    if(i==n)
    {
        ans.push_back(put.substr(1));
        return ;
    }
    string curr="";
    for(int j=i;j<n;j++)
    {
        curr+=target[j];
        if(mp.find(curr)!=mp.end())
        {
            solve(j+1,n,target,mp,ans,put+" "+curr);
        }
    }
    return ;
}
vector<string> wordBreak(string &s, vector<string> &arr)
{
    unordered_map<string,int>mp;
    for(int i=0;i<arr.size();i++) mp[arr[i]]++;
    vector<string>ans;
    solve(0,s.size(),s,mp,ans,"");
    return ans;
}
