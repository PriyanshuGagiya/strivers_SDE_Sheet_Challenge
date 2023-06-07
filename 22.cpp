#include <bits/stdc++.h>
//https://www.codingninjas.com/codestudio/problems/longest-subarray-zero-sum_8230747?challengeSlug=striver-sde-challenge&leftPanelTab=1
int LongestSubsetWithZeroSum(vector < int > arr) 
{
    int n=arr.size();
    unordered_map<int,int>mp;
    int sum=0;
    int ans=0;
    for(int i=0;i<n;i++)
    {
        sum+=arr[i];
        if(sum==0)
        {
          ans=max(ans,i+1);
        }
        if(mp.find(sum)!=mp.end())
        {
          ans=max(ans,i-mp[sum]);
        }
        else
        mp[sum]=i;
    }
    return ans;
}
