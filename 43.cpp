//https://www.codingninjas.com/codestudio/problems/maximum-meetings_8230795?challengeSlug=striver-sde-challenge&leftPanelTab=1
#include <bits/stdc++.h> 
vector<int> maximumMeetings(vector<int> &start, vector<int> &end) 
{
    vector<vector<int>>interval;
    int n=start.size();
    for(int i=0;i<n;i++)
    {
      interval.push_back({end[i], i + 1, start[i]});
    }
    sort(interval.begin(),interval.end());
    vector<int>ans;
    ans.push_back(interval[0][1]);
    int j=interval[0][0];
    for(int i=1;i<n;i++)
    {
        if(interval[i][2]>j)
        {
                j=interval[i][0];
                ans.push_back(interval[i][1]);
        }
    }
    return ans;


}
