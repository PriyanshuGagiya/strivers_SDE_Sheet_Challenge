#include <bits/stdc++.h>
//https://www.codingninjas.com/codestudio/problems/count-subarrays-with-given-xor_8230830?challengeSlug=striver-sde-challenge&leftPanelTab=3
int subarraysXor(vector<int> &arr, int x)
{
    int n=arr.size();
    int k=0;
    for(int i=0;i<n;i++)
    {
        int cur=arr[i];
        if(cur==x)
        k++;   
        for(int j=i+1;j<n;j++)
        {   cur=cur^arr[j];
            if (cur == x) 
            {
              k++;
            }
        }
    }
    return k;
}
