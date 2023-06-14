#include <bits/stdc++.h> 
//https://www.codingninjas.com/codestudio/problems/compare-version-numbers_8230793?challengeSlug=striver-sde-challenge&leftPanelTab=1

int compareVersions(string a, string b) 
{
    int n=a.size();
    int m=b.size();
    int i = 0, j = 0;
    
    while (i <n || j < m) 
    {
        long long x = 0, y = 0;
        while (i < n && a[i] != '.') x = x * 10 + (a[i++] - '0');
        while (j < m && b[j] != '.') y = y * 10 + (b[j++] - '0');
        if (x > y) return 1;
        if (x < y) return -1;
        i++;
        j++;
    }
    return 0;

}
