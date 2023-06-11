#include <bits/stdc++.h> 
//https://www.codingninjas.com/codestudio/problems/subset-sum_8230859?challengeSlug=striver-sde-challenge&leftPanelTab=1
void solve(int idx, int sum,vector<int> &num,vector<int> &ans)
{
        if(idx == num.size())
        {
            ans.push_back(sum);
            return;
        }
        solve(idx+1, sum+num[idx],num, ans);
        solve(idx+1, sum,num, ans);
}
vector<int> subsetSum(vector<int> &num)
{
    vector<int> ans;
    solve(0, 0,num, ans);
    sort(ans.begin(), ans.end());
    return ans;
}
