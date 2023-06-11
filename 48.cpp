#include<algorithm>
//https://www.codingninjas.com/codestudio/problems/maximum-activities_8230800?challengeSlug=striver-sde-challenge&leftPanelTab=3
int maximumActivities(vector<int> &start, vector<int> &finish) 
{
    vector<pair<int,int>>interval;
    int n=start.size();
    for(int i=0;i<n;i++)
    {
        interval.push_back({finish[i],start[i]});
    }
    sort(interval.begin(),interval.end());
    int limit=interval[0].first;
    int ans=1;
    for(int i=1;i<n;i++)
    {
        if(interval[i].second>=limit)
        {
            limit=interval[i].first;
            ans++;
        }
    }
    return ans;
}
