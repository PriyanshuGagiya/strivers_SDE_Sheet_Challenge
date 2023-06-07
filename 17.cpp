//https://www.codingninjas.com/codestudio/problems/unique-paths_8230802?challengeSlug=striver-sde-challenge&leftPanelTab=1
#include <bits/stdc++.h> 
int uniquePaths(int m, int n) 
{
	// Write your code here.
	// ways=n+m-2Cm-1
	long long numerator=1;
	long long denomenator=1;
	long long j=1ll*n+m-2;
	for(long long i=1ll*m-1;i>=1;i--)
	{
		numerator=numerator*1ll*j;
		denomenator=denomenator*1ll*i;
		j--;
	}
	return (int) (numerator/denomenator);
}
