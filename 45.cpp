#include <bits/stdc++.h> 
//https://www.codingninjas.com/studio/problems/job-sequencing-problem_8230832?challengeSlug=striver-sde-challenge&leftPanelTab=1
int jobScheduling(vector<vector<int>> &jobs)
{
    // Write your code here
    priority_queue<int>pq;
    unordered_map<int,vector<int>>mp;
    int mx=0;
    for(int i=0; i<jobs.size(); i++)
    {
        mx=max(mx, jobs[i][0]);
        mp[jobs[i][0]].push_back(jobs[i][1]);
    }
    int ans=0;
    for(int i=mx; i>0; i--)
    {
          for (auto &q : mp[i]) 
          {
            pq.push(q);
          }
          if(pq.size()==0)
          {
              continue;
          }
          ans += pq.top();
          pq.pop();  
    }
    return ans;
}
