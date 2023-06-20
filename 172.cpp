#include <bits/stdc++.h>
//https://www.codingninjas.com/studio/problems/longest-increasing-subsequence_8230689?challengeSlug=striver-sde-challenge&leftPanelTab=1
int longestIncreasingSubsequence(int arr[], int n)
{
    // Write Your Code here
    vector<int>ans;
    ans.push_back(arr[0]);
    for(int i=1;i<n;i++)
    {
        if(ans.back()<arr[i])
        {
            ans.push_back(arr[i]);
        }
        else
        {
            auto it=lower_bound(ans.begin(),ans.end(),arr[i]);
            *it=arr[i];
        }
    }
    return ans.size();
}
