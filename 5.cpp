//https://www.codingninjas.com/codestudio/problems/sort-0-1-2_8230695?challengeSlug=striver-sde-challenge&leftPanelTab=1
#include <bits/stdc++.h> 
void sort012(int *arr, int n)
{
   //   Write your code here
   int zero=0,one=0;
   for(int i=0;i<n;i++)
   {
      if(arr[i]==1)
      {
         one++;
      }
      if(!arr[i])
      {
         zero++;
      }
   }
   int i=0;
   while(zero)
   {
      arr[i++]=0;
      zero--;
   }
   while(one)
   {
      arr[i++]=1;
      one--;
   }
   while(i<n)
   {
      arr[i++]=2;
   }

}
