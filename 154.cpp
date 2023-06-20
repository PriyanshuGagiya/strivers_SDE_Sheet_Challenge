#include <bits/stdc++.h> 
//https://www.codingninjas.com/studio/problems/count-distinct-element-in-every-k-size-window_8230749?challengeSlug=striver-sde-challenge&leftPanelTab=1
vector<int> countDistinctElements(vector<int> &arr, int k) 
{
    // Write your code here
    int n=arr.size();
    unordered_map<int,int>mp;
    for(int i=0;i<k;i++)
    {
        mp[arr[i]]++;
    }
    vector<int>ans;
    ans.push_back(mp.size());
    int i=0;
    for(int j=k;j<n;j++)
    {
        
        mp[arr[j]]++;
        mp[arr[i]]--;
        if(mp[arr[i]]==0)
        {
            mp.erase(mp.find(arr[i]));
        }
        i++;
        ans.push_back(mp.size());
    }
    return ans;
}
