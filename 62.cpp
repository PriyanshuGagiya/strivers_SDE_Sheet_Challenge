//https://www.codingninjas.com/codestudio/problems/matrix-median_8230735?challengeSlug=striver-sde-challenge&leftPanelTab=1
#include <bits/stdc++.h>
int getMedian(vector<vector<int>> &arr)
{
    // Write your code here.
    int low=INT_MAX;
    int high=0;
    int n=arr.size();
    int m=arr[0].size();
    for(int i=0;i<n;i++)
    {
        low=min(arr[i][0],low);
        high=max(arr[i][m-1],high);
    }
    int target=((n*m)+1)/2;
    while(low<=high)
    {
        int mid=low+(high-low)/2;
        int ans=0;
        for(int i=0;i<n;i++)
        {
            auto it=upper_bound(arr[i].begin(),arr[i].end(),mid);
            ans+=(it-arr[i].begin());
        }
        if(ans<target)
        {
            low=++mid;
        }
        else
        {
            high=--mid;
        }
    }
    return low;


}
