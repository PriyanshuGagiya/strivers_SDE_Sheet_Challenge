#include <algorithm>
#include<set>
//https://www.codingninjas.com/codestudio/problems/combination-sum-ii_8230820?challengeSlug=striver-sde-challenge&leftPanelTab=3
//partially accepted
void solve(int idx,int sum,vector<int>&arr,vector<int> &num,
set<vector<int>>&ans)
{
        
        if(idx == arr.size())
        {
            if(sum==0)
            {
                ans.insert(num);
            }
            return;
        }
	
        num.push_back(arr[idx]);
        solve(idx+1,sum-arr[idx],arr,num, ans);
        num.pop_back();
        solve(idx+1,sum,arr,num, ans);
}
vector<vector<int>> combinationSum2(vector<int> &arr, int n, int target)
{
	// Write your code here.
	sort(arr.begin(),arr.end());
	vector<int>temp;
    set<vector<int>>ans;
    solve(0,target,arr,temp,ans);
	vector<vector<int>>res(ans.begin(),ans.end());
    return res;
}
// best time complexity accepted
#include <algorithm>
#include<set>
void solve(int idx,int sum,vector<int>&arr,vector<int> &num,
vector<vector<int>>&ans)
{
        
        if(sum==0)
		{
			ans.push_back(num);
			return;
		}
		for(int i=idx;i<arr.size();i++)
		{
			if(i>idx and arr[i]==arr[i-1]) continue;
			num.push_back(arr[i]);
			solve(i+1,sum-arr[i],arr,num,ans);
			num.pop_back();
		}
}
vector<vector<int>> combinationSum2(vector<int> &arr, int n, int target)
{
	// Write your code here.
	sort(arr.begin(),arr.end());
	vector<int>temp;
    vector<vector<int>>ans;
    solve(0,target,arr,temp,ans);
	
    return ans;
}
