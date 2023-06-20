#include <bits/stdc++.h> 
//https://www.codingninjas.com/studio/problems/kth-largest-element-in-the-unsorted-array_8230740?challengeSlug=striver-sde-challenge&leftPanelTab=1
int kthLargest(vector<int>& arr, int size, int K)
{
	// Write your code here.
	priority_queue<int,vector<int>,greater<int>>pq;
	for(int i=0;i<size;i++)
	{
			pq.push(arr[i]);
		if(pq.size()>K)
		{
			pq.pop();
		}
	
	}

	return pq.top();
}
