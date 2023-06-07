//https://www.codingninjas.com/codestudio/problems/merge-two-sorted-arrays_8230835?challengeSlug=striver-sde-challenge
#include <bits/stdc++.h>

vector<int> ninjaAndSortedArrays(vector<int>& arr1, vector<int>& arr2, int m, int n) 
{
	vector<int>ans;
	int i=0;
	int j=0;
	while(i<m and j<n)
	{
		if(arr1[i]<arr2[j])
		{
			ans.push_back(arr1[i]);
			i++;
		}
		else
		{
			ans.push_back(arr2[j]);
			j++;
		}
	}
	while(i<m)
	{
		ans.push_back(arr1[i]);
		i++;
	}
	while(j<n)
	{
		ans.push_back(arr2[j]);
		j++;
	}
	arr1=ans;
	return arr1;
}
//better approach
// #include <bits/stdc++.h> 
// vector<int> ninjaAndSortedArrays(vector<int>& arr1, vector<int>& arr2, int m, int n) {
//     int i=m-1,j=n-1;
//     int k=m+n-1;
//     while(j>=0){
//         if(arr1[i]<arr2[j]) arr1[k--]=arr2[j--];
//         else arr1[k--]=arr1[i--];
//     }
//     return arr1;
// }
