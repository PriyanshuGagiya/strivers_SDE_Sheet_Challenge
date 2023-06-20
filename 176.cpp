#include <bits/stdc++.h> 
//https://www.codingninjas.com/studio/problems/maximum-sum-increasing-subsequence_8230821?challengeSlug=striver-sde-challenge&leftPanelTab=1
int maxIncreasingDumbbellsSum(vector<int> &rack, int n)
{
	// Write your code here
	vector<int>dp(n,0);
	for(int i=0;i<n;i++) dp[i]=rack[i];
	int maxi=rack[0];
	for(int i=1;i<n;i++)
	{
		for(int j=0;j<i;j++)
		{
			if(rack[j]<rack[i] and dp[i]<dp[j]+rack[i])
			{
				dp[i]=dp[j]+rack[i];
			}
		}
		maxi=max(dp[i],maxi);
	}
	return maxi;
}
