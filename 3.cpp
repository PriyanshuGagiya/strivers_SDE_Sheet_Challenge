//https://www.codingninjas.com/codestudio/problems/next-permutation_8230741?challengeSlug=striver-sde-challenge&leftPanelTab=1
#include <bits/stdc++.h> 
vector<int> nextPermutation(vector<int> &permutation, int n)
{
    //  Write your code here.
    int ind=-1;
    for(int i=n-2;i>=0;i--)
    {
        if(permutation[i]<permutation[i+1])
        {
            ind=i;
            break;
        }
    }
    vector<int>ans=permutation;
    if(ind==-1)
    {
        reverse(ans.begin(),ans.end());
        return ans;
    }
    else
    {
        for(int i=n-1;i>ind;i--)
        {
            if(ans[i]>ans[ind])
            {
                swap(ans[i],ans[ind]);
                break;
            }
        }
        reverse(ans.begin()+ind+1,ans.end());
        return ans;
    }
}
