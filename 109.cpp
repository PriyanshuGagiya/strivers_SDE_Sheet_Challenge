#include <bits/stdc++.h> 
//https://www.codingninjas.com/codestudio/problems/count-and-say_8230807?challengeSlug=striver-sde-challenge&leftPanelTab=1
string writeAsYouSpeak(int n) 
{
	// Write your code here.
	string s="1";
	n--;
	while(n--)
	{
		int sz=s.size();
		string ans="";
		int i=0;
		while(i<sz)
		{
			int cnt=1;
			int no=s[i]-'0';
			while(i<sz-1 and s[i]==s[i+1])
			{
				cnt++;
				i++;
			}
			ans+=(to_string(cnt)+to_string(no));
			i++;
		}
		s=ans;
	}	
	return s;
}
