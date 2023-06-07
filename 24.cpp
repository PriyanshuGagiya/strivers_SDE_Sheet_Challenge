//https://www.codingninjas.com/codestudio/problems/longest-substring-without-repeating-characters_8230684?challengeSlug=striver-sde-challenge&leftPanelTab=1
#include <bits/stdc++.h> 
int uniqueSubstrings(string input)
{
    vector<int>mp(26,0);
    int i=0,j=0;
    int n=input.size();
    int ans=1;
    while(i<n)
    {
        mp[input[i]-'a']++;
        while(j<n and mp[input[i]-'a']>1)
        {
            mp[input[j]-'a']--;
            j++;
        }
        ans=max(ans,i-j+1);
        i++;
    }
    return ans;
}
