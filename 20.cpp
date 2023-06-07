#include <bits/stdc++.h>
//https://www.codingninjas.com/codestudio/problems/find-four-elements-that-sums-to-a-given-value_8230785?challengeSlug=striver-sde-challenge&leftPanelTab=1
string fourSum(vector<int> arr, int target, int n) 
{
    sort(arr.begin(),arr.end());
    for(int i=0;i<n-3;i++)
    {
        for(int j=i+1;j<n-2;j++)
        {
            int left=j+1;
            int right=n-1;
            while(left<right)
            {
                int sum=arr[i]+arr[j]+arr[left]+arr[right];
                if(sum==target)
                {
                    return "Yes";
                }
                if(sum<target)
                {
                    left++;
                }
                else
                {
                    right--;
                }
            }
        }
    }
    return "No";
}
