//https://www.codingninjas.com/codestudio/problems/return-subsets-sum-to-k_8230706?challengeSlug=striver-sde-challenge&leftPanelTab=1
void solve(int idx,int sum,vector<int>&arr,vector<int> &num,vector<vector<int>>&ans)
{
        
        if(idx == arr.size())
        {
            if(sum==0)
            {
                ans.push_back(num);
            }
            return;
        }
        num.push_back(arr[idx]);
        solve(idx+1,sum-arr[idx],arr,num, ans);
        num.pop_back();
        solve(idx+1,sum,arr,num, ans);
}
vector<vector<int>> findSubsetsThatSumToK(vector<int> arr, int n, int k)
{
    // Write your code here.
    vector<int>temp;
    vector<vector<int>>ans;
    solve(0,k,arr,temp,ans);
    return ans;
}
