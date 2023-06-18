#include <bits/stdc++.h> 
int atoi(string str) 
{
    int sign = 1, base = 0, i = 0;
    while (str[i] == ' ') { i++; }
    int n=str.size();
    while(i<n)
    {
        while(i<n and (str[i] < '0' || str[i] > '9' ))
        {
            if (str[i] == '-' || str[i] == '+')
            {
                sign = 1 - 2 * (str[i] == '-'); 
            }
            i++;
            
        }
        while (i<n and str[i] >= '0' and str[i] <= '9')
        {
            base = 10 * base + (str[i++] - '0');
        }
    }
    return base * sign;
}
