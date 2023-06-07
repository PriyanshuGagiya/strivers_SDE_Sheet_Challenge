#include <bits/stdc++.h>
//https://www.codingninjas.com/codestudio/problems/count-subarrays-with-given-xor_8230830?challengeSlug=striver-sde-challenge&leftPanelTab=3
int subarraysXor(vector<int> &arr, int x)
{
    int n=arr.size();
    int k=0;
    for(int i=0;i<n;i++)
    {
        int cur=arr[i];
        if(cur==x)
        k++;   
        for(int j=i+1;j<n;j++)
        {   cur=cur^arr[j];
            if (cur == x) 
            {
              k++;
            }
        }
    }
    return k;
}

///more optimized from solution section
#include <bits/stdc++.h>
int subarraysXor(vector<int> &arr, int x)
{
  unordered_map<int, vector<int>> valuesofxor;
  int xorvalue = 0;
  int temp = 0;
  int counter = 0;
  for (int i = 0; i < arr.size(); i++)
  {
    xorvalue = xorvalue ^ arr[i];
    if (xorvalue == x)
    {
      counter++;
    }
    temp = xorvalue ^ x;
    if (valuesofxor.find(temp) != valuesofxor.end())
    {
      counter += valuesofxor[temp].size();
    }

    valuesofxor[xorvalue].push_back(i);
  }

  return counter;
}
