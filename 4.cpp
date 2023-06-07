//https://www.codingninjas.com/codestudio/problems/maximum-subarray-sum_8230694?challengeSlug=striver-sde-challenge&leftPanelTab=1
#include <bits/stdc++.h> 
long long maxSubarraySum(int arr[], int n)
{
    long long ans=(-1e6-2);
    long long sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=1ll*arr[i];
        if(sum<0)
        {
            sum=0;
        }
         ans=max(ans,sum);
    }
    return ans;
}
