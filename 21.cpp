#include <bits/stdc++.h>
//https://www.codingninjas.com/codestudio/problems/longest-consecutive-sequence_8230708?challengeSlug=striver-sde-challenge&leftPanelTab=1
int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n) {
    // Write your code here.
    unordered_set<int>s(arr.begin(),arr.end());
    int ans=0;
    for(auto it : arr)
    {
        int cnt=0;
        if(s.find(it-1)==s.end())
        {
            int x=it;
            while(s.find(x)!=s.end())
            {
                cnt++;
                s.erase(x);
                x++;
            }
        }
        ans=max(ans,cnt);
    }
    return ans;
}
