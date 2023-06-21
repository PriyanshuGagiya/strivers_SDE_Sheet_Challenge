#include <bits/stdc++.h> 
//https://www.codingninjas.com/studio/problems/maximum-in-sliding-windows-of-size-k_8230772?challengeSlug=striver-sde-challenge&leftPanelTab=1
vector<int> slidingWindowMaximum(vector<int> &nums, int &k)
{
    vector<int> ans;
    deque<int> dq;
    int i = 0, j = 0;
    int n=nums.size();
    while(j<n) 
    {
        while (!dq.empty() and nums[dq.back()] < nums[j])
        dq.pop_back();

        dq.push_back(j);

        if (j - i + 1 < k)
        j++;

        else if (j - i + 1 == k) 
        {
            ans.push_back(nums[dq.front()]);
            if (nums[i] == nums[dq.front()])
                dq.pop_front();

            i++, j++;
        }
    }
    return ans;
}
