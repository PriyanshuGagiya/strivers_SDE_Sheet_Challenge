#include <bits/stdc++.h> 
//https://www.codingninjas.com/codestudio/problems/palindrome-partitioning_8230726?challengeSlug=striver-sde-challenge&leftPanelTab=1
bool check(string A,int s,int e)
{
    while(s<=e)
    {
        if(A[s++]!=A[e--])
        {
            return 0;
        }
    }
    return 1;
}
void solve(int idx,string s,vector<string>&temp,vector<vector<string>>&ans)
{
    if(idx==s.size())
    {
        ans.push_back(temp);
        return;
    }
    for(int i=idx;i<s.size();i++)
    {
        if(check(s,idx,i))
        {
            temp.push_back(s.substr(idx,i-idx+1));
            solve(i+1,s,temp,ans);
            temp.pop_back();
        }
    }
}
vector<vector<string>> partition(string &A) 
{
    // Write your code here.
     vector<vector<string>>ans;
    vector<string>temp;
    solve(0,A,temp,ans);
    return ans;
    
}
