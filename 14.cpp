#include <bits/stdc++.h>
//https://www.codingninjas.com/codestudio/problems/modular-exponentiation_8230803?challengeSlug=striver-sde-challenge&leftPanelTab=1
int modularExponentiation(int x, int n, int m) 
{
	long long ans=1;
	long long tmp=x;
	while(n)
	{
		if(n%2)
		{
			ans=((ans%m)*(tmp%m))%m;
		}
		tmp=((tmp%m)*(tmp%m))%m;
		n/=2;
	}
	return (int)(ans%m);


}
