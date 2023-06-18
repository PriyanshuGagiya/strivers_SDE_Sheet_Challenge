#include <bits/stdc++.h> 
//https://www.codingninjas.com/codestudio/problems/check-permutation_8230834?challengeSlug=striver-sde-challenge&leftPanelTab=1
string sortstring(string s)
{
    int freq[26]={0};
    int n=s.size();
    for(int i=0;i<n;i++)
    {
        freq[s[i]-'a']++;
    }
    string ans="";
    for(int i=0;i<26;i++)
    {
        if(freq[i])
        {
            ans+=(string(freq[i],i+'a'));
        }
    }
    return ans;

}
bool areAnagram(string &str1, string &str2)
{
    return (sortstring(str1)==sortstring(str2));
    
}
