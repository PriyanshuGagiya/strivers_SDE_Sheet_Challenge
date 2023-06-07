//https://www.codingninjas.com/codestudio/problems/find-duplicate-in-array_8230816?challengeSlug=striver-sde-challenge
#include <bits/stdc++.h>

int findDuplicate(vector<int> &arr, int n)
{
	unordered_map<int,int>mp;
	for(int i=0;i<n;i++)
	{
		mp[arr[i]]++;
		if(mp[arr[i]]>1) return arr[i];
	}
	return -1;
}
