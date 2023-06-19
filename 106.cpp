#include <bits/stdc++.h> 
//https://www.codingninjas.com/codestudio/problems/find-pattern-in-string-kmp-algorithm_8230819?challengeSlug=striver-sde-challenge&leftPanelTab=1
//kmp
#include <bits/stdc++.h> 

void lps(string p,vector<int>&temp,int pS)

{

    temp[0]=0;

    int i=0;

    int j=1;

    while(j<pS)

    {

        if(p[i]==p[j])

        {

            i++;

            temp[j]=i;

            j++;

        }

        else

        {

            if(i!=0)

            i=temp[i-1];

            else

            {

                temp[j]=0;

                j++;

            }

        }

    }

}

bool findPattern(string p, string s)

{

    // Write your code here.

    int pS=p.size();

    int sS=s.size();

    vector<int>temp(pS);

    lps(p,temp,pS);

    int i=0;

    int j=0;

    while(j<sS)

    {

        if(s[j]==p[i])

        {

            i++;

            j++;

        }

        if(i==pS)

        return true;

        else if(j<sS && s[j]!=p[i])

        {

            if(i!=0)

            i=temp[i-1];

            else

            j++;

        }

    }

    return false;

}
//methid that i used
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
