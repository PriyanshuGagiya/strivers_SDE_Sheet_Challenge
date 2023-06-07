#include <bits/stdc++.h> 
/*

    intervals[i][0] = start point of i'th interval
    intervals[i][1] = finish point of i'th interval

*/
//https://www.codingninjas.com/codestudio/problems/merge-intervals_8230700?challengeSlug=striver-sde-challenge&leftPanelTab=1
vector<vector<int>> mergeIntervals(vector<vector<int>> &intervals)
{
    // Write your code here.
    sort(intervals.begin(),intervals.end());
    vector<vector<int>>ans;
    ans.push_back(intervals[0]);
    int n=intervals.size();
    int j=0;
    for(int i=1;i<n;i++)
    {
        if(ans[j][1]>=intervals[i][0])
        {
            ans[j][1]=max(ans[j][1],intervals[i][1]);
        }
        else
        {
            ans.push_back(intervals[i]);
            j++;
        }
    }
    return ans;
}
