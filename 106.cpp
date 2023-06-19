#include <bits/stdc++.h> 
//https://www.codingninjas.com/codestudio/problems/find-pattern-in-string-kmp-algorithm_8230819?challengeSlug=striver-sde-challenge&leftPanelTab=1
bool findPattern(string p, string s)
{
    // Write your code here.
    int n=p.size();
    int m=s.size();
    for(int i=0;i<m;i++)
    {
        string check=s.substr(i,n);
        if(check==p)
        {
            return 1;
        }
    }
    return 0;
}
