//https://www.codingninjas.com/codestudio/problems/majority-element-ii_8230738?challengeSlug=striver-sde-challenge&leftPanelTab=1
#include <bits/stdc++.h>

vector<int> majorityElementII(vector<int> &arr)
{
    // Write your code here.
    unordered_set<int>s;
    int n=arr.size();
    unordered_map<int,int>mp;
	for(int i=0;i<n;i++)
	{
		mp[arr[i]]++;
		if(mp[arr[i]]>(n/3))
		{
			s.insert(arr[i]);
		}
	}
    vector<int>ans(s.begin(),s.end());
	return ans;

}

//more optimized
#include <bits/stdc++.h>

vector<int> majorityElementII(vector<int> &arr)
{
  int n = arr.size();
  int num1 = -1, num2 = -1, count1 = 0, count2 = 0;
  for (int i = 0; i < n; i++) 
  {
    if (arr[i] == num1)
      count1++;
    else if (arr[i] == num2)
      count2++;
    else if (count1 == 0) {
      num1 = arr[i];
      count1 = 1;
    } else if (count2 == 0) {
      num2 = arr[i];
      count2 = 1;
    } else {
      count1--;
      count2--;
    }
  }
  vector < int > ans;
  count1 = count2 = 0;
  for (int i = 0; i < n;i++) {
    if (arr[i] == num1)
      count1++;
    else if (arr[i] == num2)
      count2++;
  }
  if (count1 > n / 3)
    ans.push_back(num1);
  if (count2 > n / 3)
    ans.push_back(num2);
  return ans;

}
