#include <bits/stdc++.h> 
//https://www.codingninjas.com/codestudio/problems/subsets-ii_8230855?challengeSlug=striver-sde-challenge&leftPanelTab=1
void solve(int idx,vector<int>&arr,vector<int> &num,set<vector<int>>&ans)
{
        if(idx == arr.size())
        {
            vector<int>temp=num;
            sort(temp.begin(),temp.end());
            ans.insert(temp);
            return;
        }
        num.push_back(arr[idx]);
        solve(idx+1,arr,num, ans);
        num.pop_back();
        solve(idx+1,arr,num, ans);
}
vector<vector<int>> uniqueSubsets(int n, vector<int> &arr)
{
    // Write your code here.
    vector<int>temp;
    set<vector<int>>ans;
    solve(0,arr,temp,ans);
    vector<vector<int>>res(ans.begin(),ans.end());
    return res;
}
