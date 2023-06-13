//https://www.codingninjas.com/codestudio/problems/day-13-print-permutations-string_8230703?challengeSlug=striver-sde-challenge&leftPanelTab=1
#include <bits/stdc++.h>
void solve(int i,string &s,vector<string>&ans)
{
    if(i==s.size())
    {
        ans.push_back(s);
        return;
    }
    for(int idx=i;idx<s.size();idx++)
    {
        swap(s[idx],s[i]);
        solve(i+1,s,ans);
        swap(s[idx],s[i]);
    }
} 
vector<string> findPermutations(string &s) 
{
    vector<string>ans;
    solve(0,s,ans);
    return ans;
}https://www.codingninjas.com/codestudio/problems/day-13-print-permutations-string_8230703?challengeSlug=striver-sde-challenge&leftPanelTab=1
