//https://www.codingninjas.com/codestudio/problems/pair-sum_8230699?challengeSlug=striver-sde-challenge&leftPanelTab=1
#include <bits/stdc++.h>

vector<vector<int>> pairSum(vector<int> &arr, int s)
{
   unordered_map<int,int>mp;
   vector<vector<int>>ans;
   int n=arr.size();
   for(int i=0;i<n;i++)
   {
      if(mp.find(s-arr[i])!=mp.end())
      {
            for(int j=0;j<mp[s-arr[i]];j++)
            {
               vector<int>temp;
               temp.push_back(arr[i]);
               temp.push_back(s-arr[i]);
               sort(temp.begin(),temp.end());
               ans.push_back(temp);      
            }
      }
      mp[arr[i]]++;
   }
   sort(ans.begin(),ans.end());
   return ans;
}
