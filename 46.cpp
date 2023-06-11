//https://www.codingninjas.com/codestudio/problems/fractional-knapsack_8230767?challengeSlug=striver-sde-challenge&leftPanelTab=1
#include <bits/stdc++.h> 
bool cmp(pair<int, int>& item1,pair<int, int>& item2)
{
    double x=(1.00*item1.second)/(1.00*item1.first);
    double y=(1.00*item2.second)/(1.00*item2.first);
    return x>y;
}
double maximumValue (vector<pair<int, int>>& items, int n, int w)
{
    sort(items.begin(),items.end(),cmp);
    int i=0;
    double ans=0.0;
    while(i<n and w)
    {
        if(items[i].first<=w)
        {
            w-=items[i].first;
            ans+=1.00*items[i].second;
        }
        else
        {
            double x=(1.00*items[i].second)/(1.00*items[i].first);
            ans+=(x*w);
            w=0;
        }
        i++;
    }
    return ans;
}
