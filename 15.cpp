//https://www.codingninjas.com/codestudio/problems/day-6-majority-element_8230731?challengeSlug=striver-sde-challenge&leftPanelTab=1
//o(n) space
// #include <bits/stdc++.h>

// int findMajorityElement(int arr[], int n) 
// {
// 	unordered_map<int,int>mp;
// 	for(int i=0;i<n;i++)
// 	{
// 		mp[arr[i]]++;
// 		if(mp[arr[i]]>(n/2))
// 		{
// 			return arr[i];
// 		}
// 	}
// 	return -1;
// }

//o(1) space
#include <bits/stdc++.h>

int findMajorityElement(int arr[], int n) 
{
	int cnt=1;
	int mj=arr[0];
	for(int i=1;i<n;i++)
	{
		if(arr[i]!=mj)
		{
			cnt--;
		}
		else
		{
			cnt++;
		}
		if(!cnt)
		{
			cnt=1;
			mj=arr[i];
		}
	}
	cnt=0;
	for(int i=0;i<n;i++)
	{
		if(arr[i]==mj) cnt++;
	}
	if(cnt>n/2)
	{
		return mj;
	}
	return -1;
}
