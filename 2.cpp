//https://www.codingninjas.com/codestudio/problems/pascal-s-triangle_8230805?challengeSlug=striver-sde-challenge
#include <bits/stdc++.h>

vector<vector<long long int>> printPascal(int n) 
{
  // Write your code here.
  vector<vector<long long int>>ans(n);
  ans[0]={1};
  for(int i=1;i<n;i++)
  {
      ans[i].resize(i+1);
      ans[i][0]=1;
      for(int j=1;j<i;j++)
      {
          ans[i][j]=ans[i-1][j-1]+ans[i-1][j];
      }
      ans[i][i]=1;
  }
  return ans;
}
