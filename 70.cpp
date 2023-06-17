#include <algorithm>
//https://www.codingninjas.com/codestudio/problems/kth-smallest-and-largest-element-of-array_8230829?challengeSlug=striver-sde-challenge&leftPanelTab=1
vector<int> kthSmallLarge(vector<int> &arr, int n, int k)
{
	// Write your code here.
	sort(arr.begin(),arr.end());
	vector<int>ans;
	ans.push_back(arr[k-1]);
	ans.push_back(arr[n-k]);
	return ans;
}
