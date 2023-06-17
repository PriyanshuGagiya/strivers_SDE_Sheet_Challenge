#include <bits/stdc++.h> 
//codingninjas.com/codestudio/problems/chess-tournament_8230779?challengeSlug=striver-sde-challenge&leftPanelTab=1
int chessTournament(vector<int> positions , int n ,  int c)
{
	sort(positions.begin(),positions.end());
	int low=1;
	int high=positions[n-1]-positions[0];
	int ans=-1;
	while(low<=high)
	{
		int mid=low+(high-low)/2;
		int cnt=1;
		int last=positions[0];
		for(int i=1;i<n;i++)
		{
			if(positions[i]-last>=mid)
			{
				cnt++;
				last=positions[i];
			}
		}
		if(cnt>=c)
		{
			low=mid+1;
			ans=mid;
		}
		else
		{
			high=mid-1;
		}
	}
	return ans;
}
