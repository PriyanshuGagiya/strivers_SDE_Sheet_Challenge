#include <bits/stdc++.h> 
//https://www.codingninjas.com/codestudio/problems/merge-k-sorted-arrays_8230770?challengeSlug=striver-sde-challenge&leftPanelTab=1
vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    // Write your code here. 
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,
    greater<pair<int,pair<int,int>>>>pq;

    for(int i=0;i<k;i++)
    {
        pq.push({kArrays[i][0],{i,0}});
    }
    vector<int>ans;

    while(!pq.empty())
    {
        auto it=pq.top();
        pq.pop();
        int val=it.first;
        int row=it.second.first;
        int col=it.second.second;
        ans.push_back(val);
        if(col+1<kArrays[row].size())
        pq.push({kArrays[row][col+1],{row,col+1}});

    }
    return ans;
}
