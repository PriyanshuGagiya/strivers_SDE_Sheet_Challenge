#include <bits/stdc++.h> 
//https://www.codingninjas.com/codestudio/problems/day-29-k-max-sum-combinations_8230768?challengeSlug=striver-sde-challenge&leftPanelTab=1
vector<int> kMaxSumCombination(vector<int> &a, vector<int> &b, int n, int k)
{
	vector<int>ans;
	for(int i=0;i<n;i++)
	{
			for(int j=0;j<n;j++)
			{
				ans.push_back(a[i]+b[j]);
			}
	}
	sort(ans.begin(),ans.end());
	vector<int>res(ans.end()-k,ans.end());
	reverse(res.begin(),res.end());
	return res;
	
	
}
