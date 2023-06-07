//https://www.codingninjas.com/codestudio/problems/missing-and-repeating-numbers_8230733?challengeSlug=striver-sde-challenge&leftPanelTab=1
#include <bits/stdc++.h>

pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
	// Write your code here 
	long long sum=0;
	long long ssum=0;
	for(int i=0;i<n;i++)
	{
		sum+=(arr[i]);
		sum-=(i+1);
		ssum+=(arr[i]*arr[i]);
		ssum-=((i+1)*(i+1));
	}
	ssum/=sum;
	return {(ssum-sum)/2,(ssum+sum)/2};
}
