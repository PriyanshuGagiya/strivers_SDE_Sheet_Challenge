#include <bits/stdc++.h> 
//https://www.codingninjas.com/codestudio/problems/trapping-rain-water_8230693?challengeSlug=striver-sde-challenge&leftPanelTab=1
long getTrappedWater(long *arr, int n)
{
    // Write your code here.
    long leftmax=0,rightmax=0;
    int l=0,r=n-1;
    long ans=0;
    while(l<=r)
    {
        if(arr[l]<arr[r])
        {
            if(arr[l]>leftmax)
            {
                leftmax=arr[l];
            }
            else
            {
                ans+=(long)(leftmax-arr[l]);
            }
            l++;
        }
        else
        {
            if(arr[r]>rightmax)
            {
                rightmax=arr[r];
            }
            else
            {
                ans+=(long)(rightmax-arr[r]);
            }
            r--;
        }
    }
    return ans;
}
