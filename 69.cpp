#include <bits/stdc++.h> 
//https://www.codingninjas.com/studio/problems/min-heap_8230863?challengeSlug=striver-sde-challenge&leftPanelTab=1
//using data structure pq
vector<int> minHeap(int n, vector<vector<int>>& q) 
{
    // Write your code here.
    priority_queue<int,vector<int>,greater<int>>pq;
    vector<int>ans;
    for(int i=0;i<n;i++)
    {
        if(q[i][0])
        {
            ans.push_back(pq.top());
            pq.pop();
        }
        else
        {
            pq.push(q[i][1]);
        }
    }
    return ans;
}
