//https://www.codingninjas.com/codestudio/problems/k-most-frequent-elements_8230853?challengeSlug=striver-sde-challenge&leftPanelTab=1
#include <bits/stdc++.h> 
vector<int> KMostFrequent(int n, int k, vector<int> &arr)
{
    map<int,int>mp;
    for(int i=0;i<n;i++)
    {
        mp[arr[i]]++;
    }
    priority_queue<pair<int,int>>pq;
    for(auto it:mp)
    {
        pq.push({it.second,it.first});
    }
    mp.clear();
    vector<int>ans;
    for(int i=0;i<k;i++)
    {
        ans.push_back(pq.top().second);
        pq.pop();
    }
    sort(ans.begin(),ans.end());
    return ans;
}
//
#include <bits/stdc++.h> 
vector<int> KMostFrequent(int n, int k, vector<int> &arr)
{
    unordered_map<int,int>mp;
    for(int i=0;i<n;i++)
    {
        mp[arr[i]]++;
    }
    priority_queue<pair<int,int>>pq;
    for(auto it:mp)
    {
        pq.push({it.second,it.first});
    }
    mp.clear();
    vector<int>ans;
    for(int i=0;i<k;i++)
    {
        ans.push_back(pq.top().second);
        pq.pop();
    }
    sort(ans.begin(),ans.end());
    return ans;
}
