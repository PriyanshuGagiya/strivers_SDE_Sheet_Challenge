#include <bits/stdc++.h> 
//https://www.codingninjas.com/codestudio/problems/find-minimum-number-of-coins_8230766?challengeSlug=striver-sde-challenge&leftPanelTab=1
int findMinimumCoins(int amount) 
{
    // Write your code here
    int ans=0;
    if(amount>=1000)
    {
        int frac=amount/1000;
        amount-=(frac*1000);
        ans+=frac;
    }
    if(amount>=500)
    {
        int frac=amount/500;
        amount-=(frac*500);
        ans+=frac;
    }
    if(amount>=100)
    {
        int frac=amount/100;
        amount-=(frac*100);
        ans+=frac;
    }
    if(amount>=50)
    {
        int frac=amount/50;
        amount-=(frac*50);
        ans+=frac;
    }
    if(amount>=20)
    {
        int frac=amount/20;
        amount-=(frac*20);
        ans+=frac;
    }
    if(amount>=10)
    {
        int frac=amount/10;
        amount-=(frac*10);
        ans+=frac;
    }
    if(amount>=5)
    {
        int frac=amount/5;
        amount-=(frac*5);
        ans+=frac;
    }
    if(amount>=2)
    {
        int frac=amount/2;
        amount-=(frac*2);
        ans+=frac;
    }
    if(amount>=1)
    {
        int frac=amount/1;
        amount-=(frac*1);
        ans+=frac;
    }
    return ans;
}
