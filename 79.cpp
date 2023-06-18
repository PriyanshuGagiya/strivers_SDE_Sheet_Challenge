#include <bits/stdc++.h>
//https://www.codingninjas.com/codestudio/problems/power-set_8230797?challengeSlug=striver-sde-challenge&leftPanelTab=1
void solve(int i,vector<vector<int>>&ans,vector<int>&temp,vector<int>&v)
{
    if(i==v.size())
    {
        ans.push_back(temp);
        return;
    }
    temp.push_back(v[i]);
    solve(i+1,ans,temp,v);
    temp.pop_back();
    solve(i+1,ans,temp,v);
} 
vector<vector<int>> pwset(vector<int>v)
{
    //Write your code here
    vector<vector<int>>ans;
    int n=v.size();
    vector<int>temp;
    solve(0,ans,temp,v);
    sort(ans.begin(),ans.end());
    return ans;
}
