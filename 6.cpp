//https://www.codingninjas.com/codestudio/problems/best-time-to-buy-and-sell-stock_8230746?challengeSlug=striver-sde-challenge&leftPanelTab=1
#include <bits/stdc++.h> 
int maximumProfit(vector<int> &prices)
{
    int n=prices.size();
    int ans=0;
    int mini=prices[0];
    for(int i=0;i<n;i++)
    {
        if(prices[i]<mini)
        {
            mini=prices[i];
        }
        ans=max(ans,prices[i]-mini);
    }    
    return ans;
}
