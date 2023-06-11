//https://www.codingninjas.com/codestudio/challenges/striver-sde-challenge?activeProblems=true
#include <bits/stdc++.h>
vector<vector<int>> findTriplets(vector<int> A, int n, int K) 
{
	sort(A.begin(),A.end());
	set<vector<int>>s;
	for(int i=0;i<n-2;i++)
	{
		int sum=A[i];
		int j=i+1;
		int k=n-1;
		while(j<k)
		{
			sum=A[i]+A[j]+A[k];
			if(sum<K)
			{
				j++;
			}
			else if(sum>K)
			{
				k--;
			}
			else
			{
				vector<int>temp;
				temp.push_back(A[i]);
				temp.push_back(A[j]);
				temp.push_back(A[k]);
				s.insert(temp);
				j++;
				k--;
			}
		}
	}
	vector<vector<int>>ans(s.begin(),s.end());
	return ans;

}
